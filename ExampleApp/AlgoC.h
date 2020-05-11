#pragma once

#include "AlgoModule.h"
#include "AlgoCSettings.h"

class AlgoC : public algolab::AlgoModule
{
public:
    virtual ~AlgoC();

    static std::unique_ptr<algolab::AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<algolab::AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<algolab::SignalBase> createSignal() override;
    virtual void setSettings(const algolab::AlgoSettings&) override;

protected:
    AlgoC(const std::string& algo_name);

    virtual bool run(const algolab::ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result) override;

private:

    AlgoCSettings _current_settings;
};
