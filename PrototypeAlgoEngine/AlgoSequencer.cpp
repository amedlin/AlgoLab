#include "stdafx.h"

#include "AlgoSequencer.h"


AlgoSequencer::AlgoSequencer()
{
}

AlgoSequencer::~AlgoSequencer()
{
}

std::string AlgoSequencer::sequence() const
{
    std::string result;
    for (auto a: _sequence)
    {
        result += std::to_string(a.first) + ": " + a.second->name() + "\n";
    }
    return result;
}
