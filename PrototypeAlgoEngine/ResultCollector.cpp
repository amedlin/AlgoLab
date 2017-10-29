#include "stdafx.h"

#include "ResultCollector.h"

using namespace algolab;

ResultCollector::ResultCollector()
{
}

ResultCollector::~ResultCollector()
{
}

void ResultCollector::collect(std::shared_ptr<SignalBase> signal)
{
    std::lock_guard<std::mutex> lock(_mutex);
    _signals.insert(signal);
}
