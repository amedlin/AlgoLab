#pragma once

#include "Introspector.h"
#include "AlgoSettings.h"
#include "Versioned.h"

class InputSettings : public Introspector, public AlgoSettings, public Versioned
{
public:
    InputSettings();
    virtual ~InputSettings();

private:

};

InputSettings::InputSettings()
{
}

InputSettings::~InputSettings()
{
}
