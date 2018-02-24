#pragma once

#include "serializable.h"

#include <string>

namespace algolab
{

class SignalBase : public Serializable
{
public:
    virtual ~SignalBase()
    {
    }

    const std::string& signalName() const
    {
        return _name;
    }

    virtual std::string toString() const = 0;

protected:
    SignalBase(const std::string& name = "")
    {
        if (!name.empty())
        {
            setSignalName(name);
        }
    }

    void setSignalName(const std::string& name)
    {
        _name = name;
    }

private:
    std::string _name;
};

}
