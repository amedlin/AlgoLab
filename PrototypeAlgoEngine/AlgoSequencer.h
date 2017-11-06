#pragma once

#include "serializable.h"
#include "AlgoModule.h"
#include "future_promise.h"

#include <unordered_set>
#include <memory>
#include <map>
#include <vector>
#include <thread>

namespace algolab
{

class ResultCollector;

class AlgoSequencer : public Serializable
{
public:
    AlgoSequencer();
    virtual ~AlgoSequencer();

    //! Add a new AlgoModule to the sequencer. 
    //! NOTE: Probably ONLY needs to be called by AlgoFramework.
    void add(std::shared_ptr<AlgoModule> algo_module);

    //! The native concurrency supported by the host platform.
    unsigned int concurrencyCount() const
    {
        return _num_cpu_cores;
    }

    //! Query sequencer for the projected execution sequence of algorithms, based on those the sequencer knows about.
    std::string getRunSequence() const;

    //! Prepare the set of algorithms for automatic threaded execution. Returns false if preparation fails.
    bool prepare(ResultCollector& collector);

    //! Check whether prepare has been called successfully.
    bool isPrepared() const
    {
        return _prepared;
    }

    //! Run the sequence of algorithms
    void run();

private:
    // Set of modules that share same precedence
    using ModuleSet = std::unordered_set<std::shared_ptr<AlgoModule> >;
    // Ordered set of modules by precedence
    using Sequence = std::map<AlgoModule::Precedence, ModuleSet>;

    //! Container that manages the sequencing of algorithms
    Sequence _sequence;

    //! Platform native concurrency
    const unsigned int _num_cpu_cores;

    //! Event (call set_value()) used to kick off the run of sequenced AlgoModules
    SignalPromise _kickoff_thread_0;
    
    //! Threads that have been created by the sequencer and not yet joined
    std::vector<std::thread> _threads;

    bool _prepared = {false};
};

}
