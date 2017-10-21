#pragma once

#include "AlgoModule.h"
#include "AlgoA.h"

class AlgoB : public AlgoModule
{
public:
    virtual ~AlgoB();

    static std::unique_ptr<AlgoModule> create();

    // Overrides
    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<SignalBase> createSignal() override;
    virtual void setSettings(const AlgoSettings&) override;

protected:
    AlgoB();

private:

};
