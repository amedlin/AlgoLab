#pragma once

#include <cstdint>

class BasePrecedence {};
class VoidSettings {};
class VoidSignal {};

template <class SE, class SG>
class AlgoTraitsFoundation
{
public:
    typedef typename SE SettingsType;
    typedef typename SG SignalType;
};

template <class SE, class SG, class P = BasePrecedence>
class AlgoTraits : public AlgoTraitsFoundation<SE, SG>
{
public:
    static const int16_t PRECEDENCE = P::PRECEDENCE + 1;
    typedef typename SE SettingsType;
    typedef typename SG SignalType;
};

template<class SE, class SG>
class AlgoTraits<SE, SG, BasePrecedence>
{
public:
    static const int16_t PRECEDENCE = 0;
    typedef typename SE SettingsType;
    typedef typename SG SignalType;
};

