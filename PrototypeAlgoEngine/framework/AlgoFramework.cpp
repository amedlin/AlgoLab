#include "stdafx.h"

#include "AlgoFramework.h"

#include <iostream>
#include <cassert>

using namespace algolab;

AlgoFramework::AlgoFramework()
{
}

AlgoFramework::~AlgoFramework()
{
}

bool AlgoFramework::addAlgoModule(std::shared_ptr<AlgoModule> algo)
{
    _algo_sequencer.add(algo);
    return true;
}

std::string AlgoFramework::versionString()
{
    return "0.1";
}

void AlgoFramework::displaySequence()
{
    std::cout << _algo_sequencer.getRunSequence() << std::endl;
}

bool AlgoFramework::prepare()
{
    // Set up the initial threads in a wait state, ready to run.

    return _algo_sequencer.prepare(_result_collector);
}

bool algolab::AlgoFramework::ready() const
{
    return true;
}

void algolab::AlgoFramework::run()
{
    assert(_algo_sequencer.isPrepared());
    _algo_sequencer.run();
}

void algolab::AlgoFramework::report()
{
    _result_collector.report();
}

