#pragma once

#include <memory>

class AlgoSettings;

class AlgoSettingsFactory
{
public:
    virtual ~AlgoSettingsFactory()
    {
    }

    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() = 0;

protected:
    AlgoSettingsFactory()
    {
    }

private:

};

