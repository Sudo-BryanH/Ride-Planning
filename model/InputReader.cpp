#include "InputReader.h"




InputReader::InputReader()
{
    Node * pmale = new Node();
    Node * pfemale = new Node();
    Node * pmisc = new Node();

    DNode * dmale = new DNode();
    DNode * dfemale = new DNode();
    DNode * dmisc = new DNode();


    pmap.emplace("male", pmale);
    pmap.emplace("female", pfemale);
    pmap.emplace("misc", pmisc);

    dmap.emplace("male", dmale);
    dmap.emplace("female", dfemale);
    dmap.emplace("misc", dmisc);

}

void InputReader::addToDmap(Driver & d)
{
    DNode * n = new DNode(d);

    if (d.getGroup() != "_")
    {
        if (dmap.count(d.getGroup()) == 0)
        {
            DNode * sentinel = new DNode();
            sentinel->next = n;
            n->prev = sentinel;
            sentinel->prev = n;
            n->next = sentinel;

            dmap.emplace(d.getGroup(), sentinel);
        } else {
            DNode * at = dmap.find(d.getGroup())->second;
            addNode(at, n);
        }

    } else if (d.getGender() != "_")
    {
        if (d.getGender() == "female")
        {
            DNode * at = dmap.find("female")->second;
            addNode(at, n);

        } else
        {
            DNode * at = dmap.find("male")->second;
            addNode(at, n);
        }
        
    } else
    {
        DNode * at = dmap.find("misc")->second;

        addNode(at, n);

    }


}

void InputReader::addToPmap(Person & d)
{
    Node * n = new Node(d);

    if (d.getGroup() != "_")
    {
        if (pmap.count(d.getGroup()) == 0)
        {
            Node * sentinel = new Node();
            sentinel->next = n;
            n->prev = sentinel;
            sentinel->prev = n;
            n->next = sentinel;

            pmap.emplace(d.getGroup(), sentinel);
        } else {
            Node * at = pmap.find(d.getGroup())->second;
            addNode(at, n);
        }

    } else if (d.getGender() != "_")
    {
        if (d.getGender() == "female")
        {
            Node * at = pmap.find("female")->second;
            addNode(at, n);

        } else
        {
            Node * at = pmap.find("male")->second;
            addNode(at, n);
        }
        
    } else
    {
        Node * at = pmap.find("misc")->second;

        addNode(at, n);
    }


}

void InputReader::addNode(Node * at, Node * n)
{
        // Node * temp = at->next;
        // at->next = n;
        // n->next = temp;
        // n->prev = at;
        Node * temp = at->prev;
        at->prev = n;
        n->next = at;
        n->prev = temp;
        temp->next = n;
}

void InputReader::addDNode(DNode * at, DNode * n)
{

        DNode * temp = at->prev;
        at->prev = n;
        n->next = at;
        n->prev = temp;
        temp->next = n;
}

unordered_map<string, Node*> InputReader::getPmap()
{
    return pmap;
}

unordered_map<string, DNode*> InputReader::getDmap()
{
    return dmap;
}