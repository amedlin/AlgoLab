#pragma once

// Call this "AlgoLab" --> namespace algolab

#include "serializable.h"
#include "Versioned.h"
#include "SettingsManager.h"
#include "AlgoSequencer.h"
#include "AlgoModule.h"
#include "ResultCollector.h"

#include <memory>

namespace algolab
{

class AlgoFramework : public Serializable, public Versioned
{
public:
    AlgoFramework();
    ~AlgoFramework();

    bool addAlgoModule(std::shared_ptr<AlgoModule> algo); // unique_ptr: assume for now that AlgoFramework takes ownership

    // Overrides
    virtual std::string versionString() override;

    void displaySequence();

    bool prepare();
    bool ready() const;

private:
    SettingsManager _settings_mgr;
    AlgoSequencer _algo_sequencer;
    ResultCollector _result_collector;
};

}
