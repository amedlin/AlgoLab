#pragma once

#include "serializable.h"
#include "AlgoSettingsFactory.h"
#include "SignalFactory.h"
#include "AlgoSettings.h"
#include "future_promise.h"

#include <list>
#include <future>
#include <memory>

namespace algolab
{
class ResultCollector;

// Heap only object
class AlgoModule : public Serializable, public AlgoSettingsFactory, public SignalFactory
{
public:
    using Precedence = std::size_t;

    virtual ~AlgoModule();

    virtual void setSettings(const AlgoSettings&) = 0;

    //! Thread entry point
    bool exec(ResultCollector& collector);

    //! Get the Precedence
    Precedence precedence() const
    {
        return _precedence;
    }

    //! The the string identifier for this module
    std::string name() const
    {   // requires mutex lock for thread safety
        return _name;
    }

    //! Whether this AlgoModule is the root (initial trigger signal) for the composite algorithm
    //! TODO: Is this needed? What about the possibility that there can be multiple initial modules?
    bool isRoot() const
    {
        return _is_root;
    }

    //! Check whether the linkages between AlgoModules has any close loops.
    bool networkIsClosed();

    //! Whether this module depends on any precedent modules.
    bool hasPrecedents() const
    {
        return !_precedents.empty();
    }

    //! Query this AlgoModule to find out how many concurrent threads (maximum) it will run internally.
    virtual size_t getConcurrency() const
    {
        return 1;
    }

    //! Provide futures to AlgoModules that depend on me.
    SignalReady provideFutureWaitObject();

    //! Receive futures from AlgoModules that this module depends on. Return false if something goes wrong.
    //! All dependency relationships must be set (\sa setModuleDependency) before calling this function.
    //! Note: this might only need to be accessible to AlgoSequencer.
    bool receiveFutureWaitObjects();

    //! Receive a specific provided future wait object
    void receiveFutureWaitObject(SignalReady fut);

    //! Establish dependency relationship from precedent to dependent, which guarantees that the precedent's
    //! Precedence is lower (higher priority) than the dependents.
    static bool setModuleDependency(std::shared_ptr<AlgoModule> precedent, std::shared_ptr<AlgoModule> dependent);

    // Disable copy and move
    AlgoModule(const AlgoModule &) = delete;
    AlgoModule& operator=(const AlgoModule &) = delete;
    AlgoModule(AlgoModule &&) = delete;
    AlgoModule& operator=(AlgoModule &&) = delete;

protected:
    AlgoModule(const std::string& name);

    //! Run main body of this algorithm
    virtual bool run(const ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result);

private:

    //! Re-evaluate precedence of this algo module and all that depend on it.
    bool reevaluatePrecedence();

    //! String identifier for this algorithm
    std::string _name;

    //! Algorithms that must execute before this one.
    std::list<std::weak_ptr<AlgoModule> > _precedents;

    //! Algorithms that must execute after this one.
    std::list<std::weak_ptr<AlgoModule> > _subsequents;

    //! Promise used to provide shared_futures to _subsequents, who wait for this promise's
    //! value to be set.
    SignalPromise _my_result;
    SignalReady _master_future;
    //! Set this to false as soon as _my_result has had its value set
    bool _promise_pending = {true};

    //! Set of futures this AlgoModule has to wait for before executing.
    std::list<SignalReady> _blocking_futures;

    //! Precedence of this algo relative to others. 0 is the highest precedence.
    Precedence _precedence = { 0 };

    //! The "root" node in the network is the unique node that must be used to trigger execution
    //! without deadlock in the situation where the network dependencies are cyclic.
    //! The root node can be triggered to execute on demand, irrespective of its precedent modules.
    bool _is_root;

    //! Visit count for when this module is visited as part of network linkage exploration
    int _network_visit_count = { 0 };

};

}
