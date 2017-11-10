#include "stdafx.h"

#include "ResultCollector.h"

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
    _signals[signal_name] = signal;
}
