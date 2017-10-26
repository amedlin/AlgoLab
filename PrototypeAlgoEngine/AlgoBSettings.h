#pragma once
#include "AlgoSettings.h"

class AlgoBSettings : public algolab::AlgoSettings
{
public:
    AlgoBSettings();
    virtual ~AlgoBSettings();

    // Overrides
    virtual std::string versionString() override;
};

