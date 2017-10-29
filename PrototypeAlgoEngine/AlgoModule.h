#pragma once

#include "serializable.h"
#include "AlgoSettingsFactory.h"
#include "SignalFactory.h"
#include "AlgoSettings.h"

#include <list>
#include <future>
#include <memory>

namespace algolab
{

// Heap only object
class AlgoModule : public Serializable, public AlgoSettingsFactory, public SignalFactory
{
public:
    using Precedence = std::size_t;

    virtual ~AlgoModule();

    virtual void setSettings(const AlgoSettings&) = 0;

    bool exec(std::shared_future<std::shared_ptr<SignalBase> > input, std::promise<std::shared_ptr<SignalBase> > output);

    Precedence precedence() const
    {
        return _precedence;
    }

    std::string name() const
    {   // requires mutex lock for thread safety
        return _name;
    }

    bool isRoot() const
    {
        return _is_root;
    }

    bool networkIsClosed();

    bool hasPrecedents() const
    {
        return !_precedents.empty();
    }

    // Query this AlgoModule to find out how many concurrent threads it will run internally.
    virtual size_t getConcurrency() const
    {
        return 1;
    }

    static bool setModuleDependency(std::shared_ptr<AlgoModule> precedent, std::shared_ptr<AlgoModule> dependent);

    AlgoModule(const AlgoModule &) = delete;
    AlgoModule & operator=(const AlgoModule &) = delete;
    AlgoModule(AlgoModule &&) = delete;
    AlgoModule & operator=(AlgoModule &&) = delete;

protected:
    AlgoModule(const std::string& name);

    virtual bool run(std::shared_ptr<const algolab::SignalBase> input_signal, std::shared_ptr<algolab::SignalBase> result);

private:

    bool reevaluatePrecedence();

    std::string _name;

    //! Algorithms that must execute before this one.
    std::list<std::weak_ptr<AlgoModule> > _precedents;

    //! Algorithms that must execute after this one.
    std::list<std::weak_ptr<AlgoModule> > _subsequents;

    Precedence _precedence = { 0 };

    // The "root" node in the network is the unique node that must be used to trigger execution
    // without deadlock in the situation where the network dependencies are cyclic.
    // The root node can be triggered to execute on demand, irrespective of its precedent modules.
    bool _is_root;

    int _network_visit_count = { 0 };
};

}
