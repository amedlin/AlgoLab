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

    //! Add a new algorithm module to the runnable composite algorithm
    bool addAlgoModule(std::shared_ptr<AlgoModule> algo); // unique_ptr: assume for now that AlgoFramework takes ownership

    //! Overrides
    virtual std::string versionString() override;

    //! Display the sequence in which algo modules will run when run() is called.
    void displaySequence();

    //! Prepare to run. (Sets up threads.) Must be called before calling run().
    bool prepare();

    //! OBSOLETE?
    bool ready() const;

    //! Run the composite algorithm
    void run();

    //! Report the results that were collected.
    void report();

private:
    //! Central manager for algorithm settings
    SettingsManager _settings_mgr;

    //! Master control for algorithm sequencing logic
    AlgoSequencer _algo_sequencer;

    //! Global container for collection of algorithm results as they are generated
    ResultCollector _result_collector;
};

}
