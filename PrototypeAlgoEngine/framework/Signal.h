#pragma once

#include "SignalBase.h"
#include "Versioned.h"

#include <map>
#include <vector>

// A signal is composed of a set of channels. Each channel is a time series of scalar values.
// vector signals can be decomposed into scalar components.
// Each channel is addressed by a KEY. The VALUE associated with each channel KEY is 
// comprised of a time series of values of a specific TYPE. Preferably each such TYPE also
// allows for an uninitialized or default value, which is assigned to missing data in the series.
// The output from a given algorithm is a collection of such signals.

namespace algolab
{

// Encapsulates time series of one particular signal.
template<typename _KeyType, typename _ValueType>
class Signal : public SignalBase, public Versioned
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
