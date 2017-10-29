#pragma once

#include <cassert>

namespace algolab
{

// Assert cast on pointers
template<typename T, typename U>
inline T* assert_cast(U* obj)
{
#ifdef NDEBUG
    return static_cast<T*>(obj);
#else
    T* result = dynamic_cast<T*>(obj);
    assert(result != nullptr);
    return result;
#endif
}

// Assert cast on references
template<typename T, typename U>
inline T& assert_cast(U& obj)
{
#ifdef NDEBUG
    return static_cast<T&>(obj);
#else
    // This cast can throw exception.
    T& result = dynamic_cast<T&>(obj);
    return result;
#endif
}

}
