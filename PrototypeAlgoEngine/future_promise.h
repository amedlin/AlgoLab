#pragma once

#include "SignalBase.h"

#include <future>
#include <memory>

namespace algolab
{
    using SignalPromise = std::promise<std::shared_ptr<algolab::SignalBase> >;
    using SignalReady = std::shared_future<std::shared_ptr<algolab::SignalBase> >;
}
