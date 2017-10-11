#pragma once

#include "Introspector.h"
#include "SignalBase.h"
#include "Versioned.h"

#include <map>
#include <vector>

template<typename KeyType, typename ValueType>
class Signal : public Introspector, public SignalBase, public Versioned
{
public:
    virtual ~Signal()
    {
    }

protected:
    Signal()
    {
    }

protected:
    using Container = std::map<KeyType, std::vector<ValueType> >;

    Container& data()
    {
        return _signal_data;
    }

private:
    Container _signal_data;
};

