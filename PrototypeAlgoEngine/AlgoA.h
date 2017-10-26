#pragma once

#include "AlgoModule.h"
#include "AlgoASettings.h"
//#include "AlgoAResults.h"

class AlgoA : public algolab::AlgoModule
{
public:
    virtual ~AlgoA();

    static std::unique_ptr<algolab::AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<algolab::AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<algolab::SignalBase> createSignal() override;
    virtual void setSettings(const algolab::AlgoSettings&) override;

protected:
    AlgoA(const std::string& algo_name);

private:

    AlgoASettings _current_settings;
};

