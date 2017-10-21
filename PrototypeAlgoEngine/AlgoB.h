#pragma once

#include "AlgoModule.h"

class AlgoB : public AlgoModule
{
public:
    virtual ~AlgoB();

    static std::unique_ptr<AlgoModule> create(const std::string& algo_name = "");

    // Overrides
    virtual std::shared_ptr<AlgoSettings> createAlgoSettings() override;
    virtual std::shared_ptr<SignalBase> createSignal() override;
    virtual void setSettings(const AlgoSettings&) override;

protected:
    AlgoB(const std::string& algo_name);

private:

};
