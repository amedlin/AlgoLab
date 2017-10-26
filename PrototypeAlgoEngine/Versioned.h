#pragma once

#include <string>

namespace algolab
{

class Versioned
{
public:
    virtual ~Versioned()
    {
    }

    virtual std::string versionString() = 0;

protected:
    Versioned()
    {
    }

private:

};

}
