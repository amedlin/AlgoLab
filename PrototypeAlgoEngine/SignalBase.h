#pragma once

#include "serializable.h"
#include "Polymorphic.h"

#include <string>

class SignalBase : public PolyMorphic, public Serializable
{
public:
    virtual ~SignalBase()
    {
    }

    const std::string& signalName() const
    {
        return _name;
    }

protected:
    SignalBase()
    {
    }

    void setSignalName(const std::string& name)
    {
        _name = name;
    }

private:
    std::string _name;
};

