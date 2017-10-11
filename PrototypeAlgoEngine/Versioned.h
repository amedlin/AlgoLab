#pragma once

#include <string>

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
