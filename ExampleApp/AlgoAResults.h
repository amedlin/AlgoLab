#pragma once
#include "Signal.h"

enum class AlgoASignals
{
    SIGNAL_0,
    SIGNAL_1
};
 
class AlgoAResults : public algolab::Signal<AlgoASignals, float>
{
public:
    AlgoAResults();
    virtual ~AlgoAResults();

    // Overrides
    virtual std::string versionString() override;

    virtual std::string toString() const override;
};

