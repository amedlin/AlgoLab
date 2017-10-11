#pragma once

#include "serializable.h"
#include <map>
#include <string>
#include <memory>

class AlgoSettings;

class SettingsManager : public Serializable
{
public:
    SettingsManager();
    ~SettingsManager();

private:
    std::map<std::string, std::shared_ptr<AlgoSettings> > _settings; // settings for class, keyed by stringified derived class name
};

