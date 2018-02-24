#include "stdafx.h"

#include <iostream>

#include "ResultCollector.h"
#include "SignalBase.h"

using namespace algolab;

ResultCollector::ResultCollector()
{
}

ResultCollector::~ResultCollector()
{
}

void ResultCollector::collect(const std::string& signal_name, std::shared_ptr<const SignalBase> signal)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _signals.insert(std::make_pair(signal_name, signal));
}

std::shared_ptr<const SignalBase> algolab::ResultCollector::viewSignal(const std::string& signal_name)
{
    SignalMap::const_iterator it = _signals.find(signal_name);
    if (it != _signals.end())
    {
        return it->second;
    }
    return std::shared_ptr<const SignalBase>();
}

void algolab::ResultCollector::report()
{
    std::cout << "Collected signals:" << std::endl;
    for (const auto& s: _signals)
    {
        std::cout << s.first << ": " << s.second->toString() << std::endl;
    }
}
