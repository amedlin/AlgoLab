#pragma once

#include "AlgoModule.h"
#include "AlgoASettings.h"

class AlgoA : public algolab::AlgoModule
{
public:
    virtual ~AlgoA();

    static std::unique_ptr<algolab::AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<algolab::AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<algolab::SignalBase> createSignal() override;
    virtual void setSettings(const algolab::AlgoSettings&) override;
    //virtual bool run(std::shared_ptr<const algolab::SignalBase> input_signal, std::shared_ptr<algolab::SignalBase> result);

protected:
    AlgoA(const std::string& algo_name);

    virtual bool run(const algolab::ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result) override;

private:

    AlgoASettings _current_settings;
};

