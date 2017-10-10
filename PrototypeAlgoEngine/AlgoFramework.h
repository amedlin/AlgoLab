#pragma once

#include "serializable.h"
#include "Versioned.h"
#include "SettingsManager.h"
#include "AlgoSequencer.h"
#include "AlgoModule.h"
#include "ResultCollector.h"

#include <memory>

class AlgoFramework : public Serializable, public Versioned
{
public:
    AlgoFramework();
    ~AlgoFramework();

    bool addAlgoModule(std::unique_ptr<AlgoModule> algo); // unique_ptr: assume for now that AlgoFramework takes ownership

private:
    SettingsManager _settings_mgr;
    AlgoSequencer _algo_sequencer;
    ResultCollector _result_collector;
};

