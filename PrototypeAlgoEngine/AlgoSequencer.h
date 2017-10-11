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

    void add(std::unique_ptr<AlgoModule> algo_module)
    {
        _sequence.insert(std::make_pair(algo_module->precedence(), std::move(algo_module)));
    }

private:
    //AlgoSequenceNode* _precedence_tree;
    std::multimap<Precedence, std::unique_ptr<AlgoModule> > _sequence;
};
