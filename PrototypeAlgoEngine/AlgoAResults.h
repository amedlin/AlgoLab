#pragma once
#include "Signal.h"

enum class AlgoASignals
{
    SIGNAL_0,
    SIGNAL_1
};
 
class AlgoAResults : public Signal<AlgoASignals, float>
{
public:
    AlgoAResults();
    virtual ~AlgoAResults();

    // Overrides
    virtual std::string versionString() override;
};

