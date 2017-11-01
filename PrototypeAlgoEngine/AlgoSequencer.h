#pragma once

#include "serializable.h"
#include "AlgoModule.h"

#include <unordered_set>
#include <memory>
#include <map>

namespace algolab
{

class ResultCollector;

class AlgoSequencer : public Serializable
{
public:
    AlgoSequencer();
    virtual ~AlgoSequencer();

    using ModuleSet = std::unordered_set<std::shared_ptr<AlgoModule> >;
    using Sequence = std::map<AlgoModule::Precedence, ModuleSet>;

    void add(std::shared_ptr<AlgoModule> algo_module);

    unsigned int concurrencyCount() const
    {
        return _num_cpu_cores;
    }

    std::string getRunSequence() const;

    bool prepare();

    void run(ResultCollector& collector);

private:
    Sequence _sequence;

    const unsigned int _num_cpu_cores;

    // Event (call set_value()) used to kick off the run of sequenced AlgoModules
    std::promise<std::shared_ptr<algolab::SignalBase> > _kickoff_thread_0;
    
};

}
