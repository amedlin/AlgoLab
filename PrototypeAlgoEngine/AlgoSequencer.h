#pragma once

#include "serializable.h"
#include "AlgoModule.h"

//#include <list>
//#include <vector>
#include <memory>
#include <map>
#include <utility>

//class AlgoSequenceNode
//{
//public:
//    AlgoSequenceNode() {}
//    ~AlgoSequenceNode() {}
//
//private:
//    std::list<std::vector<AlgoSequenceNode*> > _precedents;
//    AlgoModule* _target;
//};


class AlgoSequencer : public Serializable
{
public:
    AlgoSequencer();
    ~AlgoSequencer();

    void add(std::shared_ptr<AlgoModule> algo_module)
    {
        _sequence.insert(std::make_pair(algo_module->precedence(), algo_module));
    }

    std::string sequence() const;

private:
    //AlgoSequenceNode* _precedence_tree;
    std::multimap<AlgoModule::Precedence, std::shared_ptr<AlgoModule> > _sequence;
};
