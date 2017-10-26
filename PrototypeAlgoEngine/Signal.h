#pragma once

#include "Introspector.h"
#include "SignalBase.h"
#include "Versioned.h"

#include <map>
#include <vector>

namespace algolab
{

// Encapsulates time series of one particular signal.
template<typename _KeyType, typename _ValueType>
class Signal : public Introspector, public SignalBase, public Versioned
{
public:
    virtual ~Signal()
    {
    }

    using ValueType = _ValueType;
    using KeyType = _KeyType;

    //void append(const KeyType k, const& ValueType v)
    //{
    //    _signal_data
    //}

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

}
