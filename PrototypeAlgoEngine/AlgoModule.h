#pragma once

#include "serializable.h"
#include "AlgoSettingsFactory.h"
#include "SignalFactory.h"
#include "AlgoSettings.h"

#include <list>

// Heap only object
class AlgoModule : public Serializable, public AlgoSettingsFactory, public SignalFactory
{
public:
    using Precedence = std::size_t;

    virtual ~AlgoModule();

    virtual void setSettings(const AlgoSettings&) = 0;
    Precedence precedence() const
    {
        return _precedence;
    }

    std::string name() const
    {   // requires mutex lock for thread safety
        return _name;
    }

    static void dependsOn(std::shared_ptr<AlgoModule> precedent, std::shared_ptr<AlgoModule> dependent);

    AlgoModule(const AlgoModule &) = delete; 
    AlgoModule & operator=(const AlgoModule &) = delete; 
    AlgoModule(AlgoModule &&) = delete; 
    AlgoModule & operator=(AlgoModule &&) = delete; 

protected:
    AlgoModule(const std::string& name);

private:

    void reevaluatePrecedence();

    std::string _name;

    //! Algorithms that must execute before this one.
    std::list<std::weak_ptr<AlgoModule> > _precedents;

    //! Algorithms that must execute after this one.
    std::list<std::weak_ptr<AlgoModule> > _subsequents;

    Precedence _precedence = { 0 };
};

