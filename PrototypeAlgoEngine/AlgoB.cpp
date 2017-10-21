#include "stdafx.h"
#include "AlgoB.h"
#include "AlgoBSettings.h"
#include "AlgoBResults.h"

AlgoB::AlgoB(const std::string& algo_name) : AlgoModule(algo_name)
{
}

AlgoB::~AlgoB()
{
}

std::unique_ptr<AlgoModule> AlgoB::create(const std::string& algo_name)
{
    return std::unique_ptr<AlgoB>(new AlgoB(algo_name));
}

std::shared_ptr<AlgoSettings> AlgoB::createAlgoSettings()
{
    return std::shared_ptr<AlgoSettings>(new AlgoBSettings);
}

std::shared_ptr<SignalBase> AlgoB::createSignal()
{
    return std::shared_ptr<SignalBase>(new AlgoBResults);
}

void AlgoB::setSettings(const AlgoSettings& base)
{
    const AlgoBSettings& settings = base.asRefType<AlgoBSettings>();
}
