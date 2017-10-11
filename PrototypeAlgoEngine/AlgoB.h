#pragma once

#include "AlgoModule.h"
#include "AlgoA.h"

class AlgoB : public AlgoModule
{
public:
    AlgoB();
    virtual ~AlgoB();

    // Overrides
    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<SignalBase> createSignal() override;
    virtual void setSettings(const AlgoSettings&) override;

    DECLARE_ALGO_PRECEDENCE
};

// Instantiate algo traits flagging dependence on AlgoA
template<>
class AlgoTraits<AlgoB, AlgoA>;

//static_assert(AlgoTraits<AlgoB, AlgoA>::PRECEDENCE == 2, "");
