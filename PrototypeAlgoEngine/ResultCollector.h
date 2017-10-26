#pragma once

#include "serializable.h"
#include <memory>
#include <set>

namespace algolab
{

class SignalBase;

class ResultCollector : public Serializable
{
public:
    ResultCollector();
    virtual ~ResultCollector();

private:
    std::set<std::shared_ptr<SignalBase> > _signals; // Change to map, keyed by stringified concrete class name
};

}
