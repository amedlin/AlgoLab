#pragma once

#include "serializable.h"
#include <memory>
#include <set>
#include <mutex>

namespace algolab
{

class SignalBase;

class ResultCollector : public Serializable
{
public:
    ResultCollector();
    virtual ~ResultCollector();

    void collect(std::shared_ptr<SignalBase> signal);

private:
    std::set<std::shared_ptr<SignalBase> > _signals; // Change to map, keyed by stringified concrete class name

    std::mutex _mutex;
};

}
