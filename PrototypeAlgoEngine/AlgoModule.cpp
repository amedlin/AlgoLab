#include "stdafx.h"

#include "AlgoModule.h"

#include <algorithm>

AlgoModule::AlgoModule(const std::string& name)
    : _name(name)
{
}

AlgoModule::~AlgoModule()
{
}

void AlgoModule::dependsOn(std::shared_ptr<AlgoModule> precedent, std::shared_ptr<AlgoModule> dependent)
{
    if (precedent && dependent)
    {
        dependent->_precedents.push_back(precedent);
        precedent->_subsequents.push_back(dependent);
        dependent->reevaluatePrecedence();
    }
}

void AlgoModule::reevaluatePrecedence()
{
    Precedence new_precedence = 0;
    for (const auto& algo_ptr: _precedents)
    {
        std::shared_ptr<AlgoModule> algo = algo_ptr.lock();
        if (algo)
        {
            new_precedence = std::max(new_precedence, algo->precedence() + 1);
        }
    }
    _precedence = new_precedence;
}

