#include "stdafx.h"

#include "AlgoFramework.h"

#include <iostream>

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

