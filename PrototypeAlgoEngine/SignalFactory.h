#pragma once

#include <memory>

class Signal;

class SignalFactory
{
public:
    virtual ~SignalFactory()
    {
    }

    virtual std::shared_ptr<Signal> createSignal() = 0;

protected:
    SignalFactory()
    {
    }

private:

};

