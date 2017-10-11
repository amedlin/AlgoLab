#pragma once

#include <cstdint>

class BasePrecedence {};
//class VoidSettings {};
//class VoidSignal {};

typedef int16_t Precedence;

template <class A, class P> 
class AlgoTraits;

template<>
class AlgoTraits<BasePrecedence, BasePrecedence>
{
public:
    typedef BasePrecedence PRIOR;
    static constexpr Precedence PRECEDENCE = 0;
};

template <class A, class P = BasePrecedence>
// To support multiple precedents: Use variadic templates, constexpr and initializer lists with std::max to generate precedence at compile time
class AlgoTraits
{
public:
    typedef P PRIOR;
    static constexpr Precedence PRECEDENCE = AlgoTraits<P, AlgoTraits<P>::PRIOR>::PRECEDENCE + 1;
    //typedef typename A::Settings SettingsType;
    //typedef typename A::Signals SignalsType;
};

