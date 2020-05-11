#pragma once

#include "serializable.h"
#include "Versioned.h"

namespace algolab
{

class AlgoSettings : public Serializable, public Versioned
{
public:
    virtual ~AlgoSettings();

protected:
    AlgoSettings();

    // TODO: Make AlgoSettings serializable/deserializable to/from json format
private:

};

}
