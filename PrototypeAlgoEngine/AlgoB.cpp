#include "stdafx.h"
#include "AlgoB.h"
#include "AlgoBSettings.h"
#include "AlgoBResults.h"

AlgoB::AlgoB() : AlgoModule("Algorithm B")
{
}


AlgoB::~AlgoB()
{
}

std::unique_ptr<AlgoModule> AlgoB::create()
{
    return std::unique_ptr<AlgoB>(new AlgoB);
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
