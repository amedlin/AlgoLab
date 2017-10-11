#pragma once

#include "serializable.h"
#include "AlgoTraits.h"
#include "AlgoSettingsFactory.h"
#include "SignalFactory.h"
#include "AlgoSettings.h"

class AlgoModule : public Serializable, public AlgoSettingsFactory, public SignalFactory
{
public:
    AlgoModule();
    virtual ~AlgoModule();

    virtual void setSettings(const AlgoSettings&) = 0;
    virtual Precedence precedence() const = 0;

private:

};


#define DECLARE_ALGO_PRECEDENCE virtual Precedence precedence() const {return AlgoTraits<decltype(*this), AlgoTraits<decltype(*this)>::PRIOR>::PRECEDENCE;}

