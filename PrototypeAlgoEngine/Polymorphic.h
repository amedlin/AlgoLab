#pragma once

#include <cassert>

namespace algolab
{

class PolyMorphic
{
public:
    template <class T>
    T* asPtrType()
    {
#ifdef NDEBUG
        return static_cast<T*>(this);
#else
        T* x = dynamic_cast<T*>(this);
        assert(x != nullptr);
        return x;
#endif
}

    template <class T>
    const T* asPtrType() const
    {
        return const_cast<PolyMorphic*>(this)->asPtrType<T>();
    }

    template <class T>
    T& asRefType()
    {
#ifdef NDEBUG
        return static_cast<T&>(*this);
#else
        T* x = dynamic_cast<T>(this);
        assert(x != nullptr);
        return *x;
#endif
}

    template <class T>
    const T& asRefType() const
    {
#ifdef NDEBUG
        return static_cast<const T&>(*this);
#else
        const T* x = dynamic_cast<const T*>(this);
        assert(x != nullptr);
        return *x;
#endif
    }

protected:
    PolyMorphic() {}
    virtual ~PolyMorphic() {}

};

}
