#pragma once

#include "AlgoSettings.h"

class AlgoCSettings : public algolab::AlgoSettings
{
public:
    AlgoCSettings();
    virtual ~AlgoCSettings();

    // Overrides
    virtual std::string versionString() override;
};

