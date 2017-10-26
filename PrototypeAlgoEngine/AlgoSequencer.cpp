#include "stdafx.h"

#include "AlgoSequencer.h"

#include <utility>
#include <thread>

using namespace algolab;

AlgoSequencer::AlgoSequencer()
    : num_cpu_cores(std::thread::hardware_concurrency())
{
}

AlgoSequencer::~AlgoSequencer()
{
}

void AlgoSequencer::add(std::shared_ptr<AlgoModule> algo_module)
{
    if (!algo_module)
    {
        return;
    }
    AlgoModule::Precedence p = algo_module->precedence();
    Sequence::iterator it = _sequence.find(p);
    if (it != _sequence.end())
    {
        ModuleSet& set = it->second;
        set.insert(algo_module);
    }
    else
    {
        _sequence[p] = ModuleSet{ algo_module };
    }
}

std::string AlgoSequencer::getRunSequence() const
{
    std::string result;
    for (auto a: _sequence)
    {
        result += std::to_string(a.first) + ": ";
        for (const auto& m: a.second)
        {
            result += m->name();
            if (m->isRoot())
            {
                result += " (root";
                if (m->hasPrecedents())
                {
                    result += ",cyclic)";
                }
                else
                {
                    result += ")";
                }
            }
            result += " ";
        }
        result += "\n";
    }
    return result;
}

//#include <future>

// NEXT STEPS:
// - set up live threads corresponding to the algorithmic modules
// - set up threads with waits and notifications with dependencies as per the module network
// - test thread execution sequence
// - examine the potential issue of cyclic dependencies in more detail
//std::promise<int> p;
//std::future<int> x = p.get_future();
//std::shared_future<int> sf(std::move(x));
//std::shared_future<int> sf2(sf);
