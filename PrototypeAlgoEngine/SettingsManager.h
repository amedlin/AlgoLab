#pragma once

#include "serializable.h"
#include <map>
#include <string>
#include <memory>

class InputSettings;

class SettingsManager : public Serializable
{
public:
    SettingsManager();
    ~SettingsManager();

private:
    std::map<std::string, std::shared_ptr<InputSettings> > _settings; // settings for class, keyed by stringified derived class name
};

SettingsManager::SettingsManager()
{
}

SettingsManager::~SettingsManager()
{
}
