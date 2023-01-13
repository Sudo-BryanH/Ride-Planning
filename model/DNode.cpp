
#include "DNode.h"

DNode::DNode() : Node(d), next(this), prev(this) {}

DNode::DNode(Driver & d) : d(d), Node(d), next(NULL), prev(NULL)
{

}

Driver DNode::getPerson()
{
    return d;
}