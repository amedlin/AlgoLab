#pragma once

#include "AlgoModule.h"
#include "AlgoBSettings.h"

class AlgoB : public algolab::AlgoModule
{
public:
    virtual ~AlgoB();

    static std::unique_ptr<algolab::AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<algolab::AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<algolab::SignalBase> createSignal() override;
    virtual void setSettings(const algolab::AlgoSettings&) override;

protected:
    AlgoB(const std::string& algo_name);

    virtual bool run(const algolab::ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result) override;

private:

    AlgoBSettings _current_settings;
};
