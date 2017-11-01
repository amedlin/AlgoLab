#include "stdafx.h"

#include "AlgoSequencer.h"
#include "SignalBase.h"

#include <vector>
#include <utility>
#include <thread>
#include <future>
#include <memory>

using namespace algolab;

AlgoSequencer::AlgoSequencer()
    : _num_cpu_cores(std::thread::hardware_concurrency())
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

bool AlgoSequencer::prepare()
{
    // Process the dependency tree and set up promises and futures.
    // Only call run() if this function returns true.

    return true;
}

void AlgoSequencer::run(ResultCollector& collector)
{
    std::promise<std::shared_ptr<algolab::SignalBase> > kickoff_thread_0;
    std::shared_ptr<algolab::SignalBase> null_signal;

    std::vector<std::thread> threads;

    std::shared_future<std::shared_ptr<algolab::SignalBase>> fut = kickoff_thread_0.get_future();
    for (Sequence::value_type& set: _sequence)
    {
        for (std::shared_ptr<AlgoModule> algo: set.second)
        {
            if (!algo)
            {
                continue;
            }
            // Create thread for each and execute
            std::promise<std::shared_ptr<algolab::SignalBase> > result_signal;
            std::shared_future<std::shared_ptr<algolab::SignalBase>> next_fut = result_signal.get_future();
            std::thread thr(&AlgoModule::exec, algo, fut, std::move(result_signal));
            fut = next_fut;
            threads.push_back(std::move(thr));
        }
    }

    kickoff_thread_0.set_value(null_signal);

    for (auto& th : threads) th.join();
}

// TODO: 
// - change so that ResultCollector reference is the output container passed to all the AlgoModules
// - remove run function above, since it loops over the algo's in the wrong order for setting up 
//   futures and promises. Instead, use _subsequents in the AlgoModules to set up the network of
//   futures and promises...(?) think about some more

// More thoughts:
//
// I don't think it's possible to have the new subsequent threads spawn dynamically, as two or
// more modules running in parallel may have a common subsequent that must wait for both precedents
// to complete before starting. This would imply two unrelated threads having some requirement for
// coordination, which violates the system design.
//
// If, instead, we use the network of subsequent AlgoModule links, we must do it in a way that
// ensures the network of promises and futures exactly matches the linkages between AlgoModules,
// including the possibilities that a module may have to provide multiple promises (one to each
// subsequent) and that a module may have to wait on multiple futures (one for each precedent).
// 
// Principles:
// - Each module provides ONE promise. A promise can supply multiple shared_futures.
//   => The promise must be a member variable of the AlgoModule.
// - Each module must wait on one or more futures to provide data before they can execute.
//   => modules should get their shared_futures from their _precedent's promises.
// 
// It remains to be done to find an algorithm to set up this network of promises and futures,
// based on the AlgoModule::Precedence values and/or the data structure in AlgoSequencer and/or
// the links between modules in _precedents and _subsequents.
