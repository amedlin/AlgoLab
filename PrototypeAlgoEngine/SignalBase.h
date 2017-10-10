#pragma once

#include "serializable.h"

#include <map>
#include <vector>

template<typename KeyType, typename ValueType>
class SignalBase : public Serializable
{
public:
    virtual ~SignalBase()
    {
    }

protected:
    using Container = std::map<KeyType, std::vector<ValueType> >;

    SignalBase()
    {
    }

    Container& data()
    {
        return _signal_data;
    }

private:
    Container _signal_data;
};

