#include "InputReader.h"




InputReader::InputReader()
{
    Node * pmale = new Node();
    Node * pfemale = new Node();
    Node * pmisc = new Node();

    Node * dmale = new Node();
    Node * dfemale = new Node();
    Node * dmisc = new Node();


    pmap.emplace(make_pair("male", pmale));
    pmap.emplace(make_pair("female", pfemale));
    pmap.emplace(make_pair("misc", pmisc));

    dmap.emplace(make_pair("male", dmale));
    dmap.emplace(make_pair("female", dfemale));
    dmap.emplace(make_pair("misc", dmisc));

}

void InputReader::addToDmap(Driver & d)
{
    DNode * n = new DNode(d);

    if (d.getGroup() != "none")
    {
        if (dmap.count(d.getGroup()) == 0)
        {
            Node * sentinel = new Node();
            sentinel->next = n;
            n->prev = sentinel;
            sentinel->prev = n;
            n->next = sentinel;

            dmap.emplace(make_pair(d.getGroup(), sentinel));
        }

    } else if (d.getGender() != "none")
    {
        if (d.getGender() == "female")
        {
            Node * at = dmap.find("female")->second;
            addNode(at, n);

        } else
        {
            Node * at = dmap.find("male")->second;
            addNode(at, n);
        }
        
    } else
    {
        Node * at = dmap.find("misc")->second;

        addNode(at, n);
    }


}

void InputReader::addNode(Node * at, Node * n)
{
        Node * temp = at->next;
        at->next = n;
        n->next = temp;
        n->prev = at;
}

unordered_map<string, Node*> InputReader::getPmap()
{
    return pmap;
}

unordered_map<string, DNode*> InputReader::getDmap()
{
    return dmap;
}