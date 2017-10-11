#include "stdafx.h"

#include "AlgoFramework.h"


AlgoFramework::AlgoFramework()
{
}

AlgoFramework::~AlgoFramework()
{
}

bool AlgoFramework::addAlgoModule(std::unique_ptr<AlgoModule> algo)
{
    _algo_sequencer.add(std::move(algo));
    return true;
}

std::string AlgoFramework::versionString()
{
    return "0.1";
}
