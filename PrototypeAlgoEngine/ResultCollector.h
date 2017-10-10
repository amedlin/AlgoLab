#pragma once

#include "serializable.h"
#include <memory>
#include <set>

class Signal;

class ResultCollector : public Serializable
{
public:
    ResultCollector();
    virtual ~ResultCollector();

private:
    std::set<std::shared_ptr<Signal> > _signals; // Change to map, keyed by stringified concrete class name
};

ResultCollector::ResultCollector()
{
}

ResultCollector::~ResultCollector()
{
}