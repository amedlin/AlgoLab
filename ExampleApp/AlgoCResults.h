#pragma once
#include "Signal.h"

enum class AlgoCSignal
{
    SIGNAL_0,
    SIGNAL_1,
    SIGNAL_2
};

class AlgoCResults : public algolab::Signal<AlgoCSignal, float>
{
public:
    AlgoCResults();
    virtual ~AlgoCResults();

    // Overrides
    virtual std::string versionString() override;

    virtual std::string toString() const override;
};

