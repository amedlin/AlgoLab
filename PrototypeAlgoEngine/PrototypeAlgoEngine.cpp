// PrototypeAlgoEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "AlgoFramework.h"
#include "AlgoA.h"
#include "AlgoB.h"
#include "AlgoC.h"

#include <memory>

int main()
{
    AlgoFramework framework;

    std::shared_ptr<AlgoModule> algo_A(AlgoA::create("Algo_A"));
    std::shared_ptr<AlgoModule> algo_B(AlgoB::create("Algo_B"));
    std::shared_ptr<AlgoModule> algo_A_1(AlgoA::create("Algo_A_1"));
    std::shared_ptr<AlgoModule> algo_A_2(AlgoA::create("Algo_A_2"));
    std::shared_ptr<AlgoModule> algo_C(AlgoC::create("Algo_C"));

    AlgoModule::setModuleDependency(algo_B, algo_A_1);
    AlgoModule::setModuleDependency(algo_A, algo_B);
    AlgoModule::setModuleDependency(algo_A, algo_C);
    AlgoModule::setModuleDependency(algo_A_1, algo_A_2);
    AlgoModule::setModuleDependency(algo_C, algo_A_2);

    // Experiment: handle cyclic dependency
    AlgoModule::setModuleDependency(algo_A_2, algo_A);


    framework.addAlgoModule(algo_A);
    framework.addAlgoModule(algo_C);
    framework.addAlgoModule(algo_A_1);
    framework.addAlgoModule(algo_A_2);
    framework.addAlgoModule(algo_B);

    // Display the sequence in which these algos will be run according to the dependencies.
    framework.displaySequence();

    return 0;
}

