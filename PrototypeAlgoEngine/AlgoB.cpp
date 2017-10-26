#include "stdafx.h"
#include "AlgoB.h"
#include "AlgoBSettings.h"
#include "AlgoBResults.h"

AlgoB::AlgoB(const std::string& algo_name) : algolab::AlgoModule(algo_name)
{
}

AlgoB::~AlgoB()
{
}

std::unique_ptr<algolab::AlgoModule> AlgoB::create(const std::string& algo_name)
{
    return std::unique_ptr<AlgoB>(new AlgoB(algo_name));
}

std::shared_ptr<algolab::AlgoSettings> AlgoB::createAlgoSettings()
{
    return std::shared_ptr<algolab::AlgoSettings>(new AlgoBSettings);
}

std::shared_ptr<algolab::SignalBase> AlgoB::createSignal()
{
    return std::shared_ptr<algolab::SignalBase>(new AlgoBResults);
}

void AlgoB::setSettings(const algolab::AlgoSettings& base)
{
    const AlgoBSettings& settings = base.asRefType<AlgoBSettings>();
}
