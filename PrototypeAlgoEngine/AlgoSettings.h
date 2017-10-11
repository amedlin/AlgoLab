#pragma once

#include "serializable.h"
#include "Polymorphic.h"
#include "Introspector.h"
#include "Versioned.h"

class AlgoSettings : public PolyMorphic, public Serializable, public Introspector, public Versioned
{
public:
    virtual ~AlgoSettings();

protected:
    AlgoSettings();

private:

};
