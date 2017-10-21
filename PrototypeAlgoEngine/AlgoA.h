#pragma once

#include "AlgoModule.h"
#include "AlgoASettings.h"
//#include "AlgoAResults.h"

class AlgoA : public AlgoModule
{
public:
    virtual ~AlgoA();

    static std::unique_ptr<AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<SignalBase> createSignal() override;
    virtual void setSettings(const AlgoSettings&) override;

protected:
    AlgoA(const std::string& algo_name);

private:

    AlgoASettings _current_settings;
};

