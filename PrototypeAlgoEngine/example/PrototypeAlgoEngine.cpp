// PrototypeAlgoEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "AlgoFramework.h"
#include "AlgoA.h"
#include "AlgoB.h"
#include "AlgoC.h"

#include <memory>
#include <iostream>

int main()
{
    using namespace algolab;

    AlgoFramework framework;

    // TODO: Replace these with factory creation based on json file
    std::shared_ptr<AlgoModule> algo_A(AlgoA::create("Algo_A"));
    std::shared_ptr<AlgoModule> algo_B(AlgoB::create("Algo_B"));
    std::shared_ptr<AlgoModule> algo_A_1(AlgoA::create("Algo_A_1"));
    std::shared_ptr<AlgoModule> algo_A_2(AlgoA::create("Algo_A_2"));
    std::shared_ptr<AlgoModule> algo_C(AlgoC::create("Algo_C"));

    // TODO: Replace these with dependency graph setup automatically based on json file
    bool result;
    result = AlgoModule::setModuleDependency(algo_B, algo_A_1);
    result = AlgoModule::setModuleDependency(algo_A, algo_B);
    result = AlgoModule::setModuleDependency(algo_A, algo_C);
    result = AlgoModule::setModuleDependency(algo_A_1, algo_A_2);
    result = AlgoModule::setModuleDependency(algo_C, algo_A_2);

    // Experiment: handle cyclic dependency
    result = AlgoModule::setModuleDependency(algo_A_2, algo_A);

    // Experiment: add nasty cyclic dependency  not involving the root node
//    result = AlgoModule::setModuleDependency(algo_A_2, algo_B);

    // TODO: Replace these with automatic algo registration based on json file
    framework.addAlgoModule(algo_A);
    framework.addAlgoModule(algo_C);
    framework.addAlgoModule(algo_A_1);
    framework.addAlgoModule(algo_A_2);
    framework.addAlgoModule(algo_B);

    // Display the sequence in which these algos will be run according to the dependencies.
    framework.displaySequence();

    // Prepare framework for execution
    framework.prepare();

    if (!framework.ready())
    {
        return 1;
    }
    framework.run();

    framework.report();

    return 0;
}

