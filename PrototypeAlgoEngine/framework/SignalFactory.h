#pragma once

#include <memory>

namespace algolab
{

class SignalBase;

class SignalFactory
{
public:
    virtual ~SignalFactory()
    {
    }

    virtual std::shared_ptr<SignalBase> createSignal() = 0;

protected:
    SignalFactory()
    {
    }

private:

};

}
