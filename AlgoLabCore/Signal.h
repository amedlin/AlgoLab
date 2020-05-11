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

// References:
// https://stackoverflow.com/questions/22654422/using-stdshared-ptrvoid-to-point-to-anything (see pointer_holder code)
// https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern (similar vein to above example)
// C++ advice from Meyers:
//      - factories should always return unique_ptr, since these can be converted to shared_ptr, but not the other way around
//      -weak_ptrs are great for observer or listener design patterns, when the objects doing the notifications should not impact the resource lifetime of the listener objects
//      - weak_ptrs can be used to prevent potential cycles in shared_ptr resource ownership that can result in memory leaks.
//

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

    void append(const KeyType& k, const ValueType& v);

    virtual std::string toString() const override;

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

template<typename _KeyType, typename _ValueType>
std::string algolab::Signal<_KeyType, _ValueType>::toString() const
{
    return "Override in derived class to report signal";
}

template<typename _KeyType, typename _ValueType>
void algolab::Signal<_KeyType, _ValueType>::append(const KeyType& k, const ValueType& v)
{
    _signal_data[k].push_back(v);
}

}
