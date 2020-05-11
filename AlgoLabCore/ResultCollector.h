#pragma once

#include "serializable.h"
#include <memory>
#include <unordered_map>
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

    //! Collect a named output signal and add it to collection
    void collect(const std::string& signal_name, std::shared_ptr<const SignalBase> signal);

    std::shared_ptr<const SignalBase> viewSignal(const std::string& signal_name) const;

    void report();

private:
    using SignalMap = std::unordered_multimap<std::string, std::shared_ptr<const SignalBase> >;
    SignalMap _signals;

    //! Mutex for controlling updates to _signals
    std::mutex _mutex;
};

}
