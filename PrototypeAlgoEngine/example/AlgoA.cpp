#include "stdafx.h"
#include "AlgoA.h"
#include "AlgoASettings.h"
#include "AlgoAResults.h"
#include "cast.h"

using namespace algolab;

AlgoA::AlgoA(const std::string& algo_name) : algolab::AlgoModule(algo_name)
{
}

AlgoA::~AlgoA()
{
}

std::unique_ptr<algolab::AlgoModule> AlgoA::create(const std::string& algo_name)
{
    return std::unique_ptr<AlgoA>(new AlgoA(algo_name));
}

std::shared_ptr<algolab::AlgoSettings> AlgoA::createAlgoSettings()
{
    return std::shared_ptr<AlgoASettings>(new AlgoASettings);
}

std::shared_ptr<algolab::SignalBase> AlgoA::createSignal()
{
    return std::shared_ptr<AlgoAResults>(new AlgoAResults);
}

void AlgoA::setSettings(const algolab::AlgoSettings& base)
{
    const AlgoASettings& settings = algolab::assert_cast<const AlgoASettings>(base);
    _current_settings = settings;
}

bool AlgoA::run(const ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result)
{
    std::shared_ptr<AlgoAResults> my_result(std::dynamic_pointer_cast<AlgoAResults>(result));
    if (my_result)
    {
        my_result->append(AlgoASignals::SIGNAL_0, 0.0);
    }
    return true;
}

