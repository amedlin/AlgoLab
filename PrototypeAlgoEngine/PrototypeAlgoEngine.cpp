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

    std::unique_ptr<AlgoA> algo_A(new AlgoA);
    std::unique_ptr<AlgoB> algo_B(new AlgoB);

    framework.addAlgoModule(std::move(algo_B));
    framework.addAlgoModule(std::move(algo_A));

    return 0;
}

