
#include "DNode.h"

DNode::DNode() : Node(d) {}

DNode::DNode(Driver & d) : d(d), Node(d)
{

}

Driver DNode::getPerson()
{
    return d;
}