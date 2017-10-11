#include "stdafx.h"
#include "AlgoB.h"
#include "AlgoBSettings.h"
#include "AlgoBResults.h"

AlgoB::AlgoB()
{
}


AlgoB::~AlgoB()
{
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
