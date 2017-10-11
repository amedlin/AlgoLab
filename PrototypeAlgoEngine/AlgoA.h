#pragma once

#include "AlgoModule.h"
#include "AlgoASettings.h"
//#include "AlgoAResults.h"

class AlgoA : public AlgoModule
{
public:
    AlgoA();
    virtual ~AlgoA();

    // Overrides
    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<SignalBase> createSignal() override;
    virtual void setSettings(const AlgoSettings&) override;

    DECLARE_ALGO_PRECEDENCE

private:

    AlgoASettings _current_settings;
};

// Instantiate default algo traits
template<>
class AlgoTraits<AlgoA, BasePrecedence>;

//static_assert(AlgoTraits<AlgoA, BasePrecedence>::PRECEDENCE == 1, "");
