// PrototypeAlgoEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "AlgoFramework.h"
#include "AlgoA.h"
#include "AlgoB.h"

#include <memory>

int main()
{
    AlgoFramework framework;

    std::shared_ptr<AlgoModule> algo_A(AlgoA::create());
    std::shared_ptr<AlgoModule> algo_B(AlgoB::create());
    AlgoModule::dependsOn(algo_A, algo_B);

    framework.addAlgoModule(algo_B);
    framework.addAlgoModule(algo_A);

    framework.displaySequence();

    return 0;
}

