#pragma once

#include "serializable.h"
#include "AlgoModule.h"

#include <unordered_set>
#include <memory>
#include <map>

namespace algolab
{

class AlgoSequencer : public Serializable
{
public:
    AlgoSequencer();
    virtual ~AlgoSequencer();

    using ModuleSet = std::unordered_set<std::shared_ptr<AlgoModule> >;
    using Sequence = std::map<AlgoModule::Precedence, ModuleSet>;

    void add(std::shared_ptr<AlgoModule> algo_module);

    std::string getRunSequence() const;

private:
    Sequence _sequence;

    const unsigned int num_cpu_cores;
};

}
