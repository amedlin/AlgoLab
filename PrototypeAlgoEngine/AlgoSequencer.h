#pragma once

#include "serializable.h"
#include <list>
#include <vector>

class AlgoModule;

class AlgoSequenceNode
{
public:
    AlgoSequenceNode() {}
    ~AlgoSequenceNode() {}

private:
    std::list<std::vector<AlgoSequenceNode*> > _precedents;
    AlgoModule* _target;
};



class AlgoSequencer : public Serializable
{
public:
    AlgoSequencer();
    ~AlgoSequencer();

private:
    AlgoSequenceNode* _precedence_tree;

};

AlgoSequencer::AlgoSequencer()
{
}

AlgoSequencer::~AlgoSequencer()
{
}
