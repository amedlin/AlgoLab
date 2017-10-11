#pragma once

#include "AlgoSettings.h"

class AlgoASettings : public AlgoSettings
{
public:
    AlgoASettings();
    virtual ~AlgoASettings();

    // Overrides
    virtual std::string versionString() override;
};

