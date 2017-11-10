#pragma once

#include "SignalBase.h"

#include <future>
#include <memory>

namespace algolab
{
    using SignalPromise = std::promise<void>;
    using SignalReady = std::shared_future<void>;
}
