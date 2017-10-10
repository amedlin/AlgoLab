#pragma once

#include "Introspector.h"
#include "SignalBase.h"
#include "Versioned.h"

template<typename KeyType, typename ValueType>
class Signal : public Introspector, public SignalBase<KeyType, ValueType>, public Versioned
{
public:
    virtual ~Signal()
    {
    }

protected:
    Signal()
    {
    }

private:

};
