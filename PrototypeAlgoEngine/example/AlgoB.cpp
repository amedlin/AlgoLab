#include "stdafx.h"
#include "AlgoB.h"
#include "AlgoBSettings.h"
#include "AlgoBResults.h"
#include "AlgoAResults.h"
#include "ResultCollector.h"
#include "cast.h"

using namespace algolab;

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
    return std::shared_ptr<AlgoBSettings>(new AlgoBSettings);
}

std::shared_ptr<algolab::SignalBase> AlgoB::createSignal()
{
    return std::shared_ptr<AlgoBResults>(new AlgoBResults);
}

void AlgoB::setSettings(const algolab::AlgoSettings& base)
{
    const AlgoBSettings& settings = algolab::assert_cast<const AlgoBSettings>(base);
    _current_settings = settings;
}

bool AlgoB::run(const ResultCollector& collector, std::shared_ptr<algolab::SignalBase> result)
{
    std::shared_ptr<AlgoBResults> my_result(std::dynamic_pointer_cast<AlgoBResults>(result));
    if (my_result)
    {
        std::shared_ptr<const AlgoAResults> signal_A = std::dynamic_pointer_cast<const AlgoAResults>(
            collector.viewSignal("AlgoA results"));
        // Could use result from signal_A here as input to AlgoB.
        my_result->append(0, 1);
    }
    return true;
}
