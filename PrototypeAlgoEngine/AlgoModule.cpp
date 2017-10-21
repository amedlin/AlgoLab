#include "stdafx.h"

#include "AlgoModule.h"

#include <algorithm>
#include <stdexcept>
#include <iostream>

AlgoModule::AlgoModule(const std::string& name)
    : _name(name)
    , _is_root(true)
{
}

AlgoModule::~AlgoModule()
{
}

bool AlgoModule::networkIsClosed()
{
    if (_network_visit_count > 0)
    {
        return true;
    }
    else
    {
        _network_visit_count++;
        bool closed = false;
        for (const auto& algo_ptr: _precedents)
        {
            std::shared_ptr<AlgoModule> algo = algo_ptr.lock();
            if (algo)
            {
                closed = closed || algo->networkIsClosed();
            }
        }
        _network_visit_count--;
        return closed;
    }
}

bool AlgoModule::setModuleDependency(std::shared_ptr<AlgoModule> precedent, std::shared_ptr<AlgoModule> dependent)
{
    if (precedent && dependent && (precedent.get() != dependent.get()))
    {
        dependent->_precedents.push_back(precedent);
        precedent->_subsequents.push_back(dependent);
        if (!precedent->networkIsClosed())
        {
            // If the new link in the network creates a closed dependency loop, then the dependent had better 
            // be the "root" node that can be externally triggered to start executing.
            // Otherwise, the dependent fully relies on its precedent to trigger its execution.
            dependent->_is_root = false;
        }
        if (!dependent->isRoot())
        {
            // We don't reevaluate if the node is root, otherwise we would have an infinite recursive call.
            if (!dependent->reevaluatePrecedence())
            {
                // Unwind the changes to restore the network to prior state!
                dependent->_precedents.pop_back();
                precedent->_subsequents.pop_back();
                return dependent->reevaluatePrecedence();
            }
        }
        return true;
    }
    return false;
}

bool AlgoModule::reevaluatePrecedence()
{
    constexpr int MAX_RECURSION = 30;
    static int recursion_level = 0;
    ++recursion_level;
    if (recursion_level > MAX_RECURSION)
    {
        --recursion_level;
        throw std::logic_error("Max AlgoModule dependency level exceeded. Check whether you have introduced a cyclic dependency?");
    }

    Precedence new_precedence = 0;
    // Determine new precedence as one more than the largest precedence from preceding modules
    for (const auto& algo_ptr: _precedents)
    {
        std::shared_ptr<AlgoModule> algo = algo_ptr.lock();
        if (algo)
        {
            new_precedence = std::max(new_precedence, algo->precedence() + 1);
        }
    }
    // Assign the new precedence to self.
    if (new_precedence != _precedence)
    {
        _precedence = new_precedence;
        // Re-evaluate precedence of all modules that depend on us, recursively.
        for (const auto& algo_ptr: _subsequents)
        {
            std::shared_ptr<AlgoModule> algo = algo_ptr.lock();
            if (algo && !algo->isRoot())
            {
                // We don't reevaluate if the node is root, otherwise we would have an infinite recursive call.
                try
                {
                    bool success = algo->reevaluatePrecedence();
                    --recursion_level;
                    return success;
                }
                catch (const std::logic_error& e)
                {
                    std::cout << e.what() << std::endl;
                    --recursion_level;
                    return false;
                }
            }
        }
    }
    --recursion_level;
    return true;
}

