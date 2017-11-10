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
    for (auto& th : _threads) th.join();
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

bool AlgoSequencer::prepare(ResultCollector& collector)
{
    // Process the dependency tree and set up promises and futures.
    // Only call run() if this function returns true.
    
    bool initiating_threads = true;
    SignalReady kickoff_signal = _kickoff_thread_0.get_future();
    for (Sequence::value_type& set: _sequence)
    {
        for (std::shared_ptr<AlgoModule> algo: set.second)
        {
            if (!algo)
            {
                continue;
            }
            if (initiating_threads)
            {
                algo->receiveFutureWaitObject(kickoff_signal);
            }
            else
            {
                algo->receiveFutureWaitObjects();
            }
            // Create thread for each and execute. Initially, all will block
            // waiting for kickoff signal.
            std::thread thr(&AlgoModule::exec, algo, std::ref(collector));
            _threads.push_back(std::move(thr));            
        }
        initiating_threads = false;
    }

    _prepared = true;
    return true;
}

void AlgoSequencer::run()
{
    std::shared_ptr<algolab::SignalBase> null_signal;
    _kickoff_thread_0.set_value(null_signal);

    for (auto& th : _threads) th.join();
    _threads.clear();
}

