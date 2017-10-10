#pragma once

#include "serializable.h"

class AlgoSettings : public Serializable
{
public:
    virtual ~AlgoSettings();

    template <class T>
    T* asType()
    {
        return dynamic_cast<T>(this);
    }

    template <class T>
    T& asType()
    {
        return dynamic_cast<T&>(*this);
    }

protected:
    AlgoSettings();

private:

};
