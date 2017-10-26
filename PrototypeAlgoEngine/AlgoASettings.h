#pragma once

#include "AlgoSettings.h"

class AlgoASettings : public algolab::AlgoSettings
{
public:
    AlgoASettings();
    virtual ~AlgoASettings();

    // Overrides
    virtual std::string versionString() override;
};

