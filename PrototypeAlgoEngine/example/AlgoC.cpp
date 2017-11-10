#include "stdafx.h"
#include "AlgoC.h"
#include "AlgoCSettings.h"
#include "AlgoCResults.h"
#include "cast.h"

AlgoC::AlgoC(const std::string& algo_name) : algolab::AlgoModule(algo_name)
{
}

AlgoC::~AlgoC()
{
}

std::unique_ptr<algolab::AlgoModule> AlgoC::create(const std::string& algo_name)
{
    return std::unique_ptr<AlgoC>(new AlgoC(algo_name));
}

std::shared_ptr<algolab::AlgoSettings> AlgoC::createAlgoSettings()
{
    return std::shared_ptr<AlgoCSettings>(new AlgoCSettings);
}

std::shared_ptr<algolab::SignalBase> AlgoC::createSignal()
{
    return std::shared_ptr<AlgoCResults>(new AlgoCResults);
}

void AlgoC::setSettings(const algolab::AlgoSettings& base)
{
    const AlgoCSettings& settings = algolab::assert_cast<const AlgoCSettings>(base);
    _current_settings = settings;
}
