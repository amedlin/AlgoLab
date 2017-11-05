#pragma once

#include "serializable.h"
#include <memory>
#include <map>
#include <mutex>
#include <string>

namespace algolab
{

class SignalBase;

class ResultCollector : public Serializable
{
public:
    ResultCollector();
    virtual ~ResultCollector();

    void collect(const std::string& signal_name, std::shared_ptr<const SignalBase> signal);

private:
    std::map<std::string, std::shared_ptr<const SignalBase> > _signals; // Change to map, keyed by stringified concrete class name

    std::mutex _mutex;
};

}
