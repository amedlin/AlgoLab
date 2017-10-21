#include "stdafx.h"
#include "AlgoA.h"
#include "AlgoASettings.h"
#include "AlgoAResults.h"

AlgoA::AlgoA() : AlgoModule("Algorithm A")
{
}


AlgoA::~AlgoA()
{
}

std::unique_ptr<AlgoModule> AlgoA::create()
{
    return std::unique_ptr<AlgoA>(new AlgoA);
}

std::shared_ptr<AlgoSettings> AlgoA::createAlgoSettings()
{
    return std::shared_ptr<AlgoSettings>(new AlgoASettings);
}

std::shared_ptr<SignalBase> AlgoA::createSignal()
{
    return std::shared_ptr<AlgoAResults>(new AlgoAResults);
}

void AlgoA::setSettings(const AlgoSettings& base)
{
    const AlgoASettings& settings = base.asRefType<AlgoASettings>();
    _current_settings = settings;
}
