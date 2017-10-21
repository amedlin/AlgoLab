#include "stdafx.h"
#include "AlgoC.h"
#include "AlgoCSettings.h"
#include "AlgoCResults.h"

AlgoC::AlgoC(const std::string& algo_name) : AlgoModule(algo_name)
{
}

AlgoC::~AlgoC()
{
}

std::unique_ptr<AlgoModule> AlgoC::create(const std::string& algo_name)
{
    return std::unique_ptr<AlgoC>(new AlgoC(algo_name));
}

std::shared_ptr<AlgoSettings> AlgoC::createAlgoSettings()
{
    return std::shared_ptr<AlgoSettings>(new AlgoCSettings);
}

std::shared_ptr<SignalBase> AlgoC::createSignal()
{
    return std::shared_ptr<SignalBase>(new AlgoCResults);
}

void AlgoC::setSettings(const AlgoSettings& base)
{
    const AlgoCSettings& settings = base.asRefType<AlgoCSettings>();
}
