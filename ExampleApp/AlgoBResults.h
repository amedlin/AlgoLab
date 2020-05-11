#pragma once
#include "Signal.h"

class AlgoBResults : public algolab::Signal<int, int>
{
public:
    AlgoBResults();
    virtual ~AlgoBResults();

    // Overrides
    virtual std::string versionString() override;

    virtual std::string toString() const override;
};

