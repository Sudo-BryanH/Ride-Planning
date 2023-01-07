#include "Planner.h"






Planner::Planner(unordered_map<string, DNode * > & driverlist, unordered_map<string, Node * > & passengerlist, vector<string> & grouplist) 
{
    pub = Publisher();
    driverlist = driverlist;
    passengerlist = passengerlist;
    grouplist = grouplist;

}

void Planner::planride()
{
    for(string g : grouplist)
    {
        auto dl = driverlist.find(g);
        auto pl = passengerlist.find(g);
        sort(dl, pl);
    }

    sortgen("female");

    sortgen("male");

    sortmisc();

}

void Planner::sort(unordered_map<string, DNode *>::iterator & dl, unordered_map<string, Node *>::iterator & pl)
{

    //reminder to use plist's regular add node fn

        // if (dl != driverlist.end() && pl == passengerlist.end())
        // {
          
        // }
        // else if (dl == driverlist.end() && pl != passengerlist.end())
        // {
            
        // }
        // else
        if (dl != driverlist.end() && pl != passengerlist.end())
        {
            Node * curp = pl->second->next;
            DNode * curd = dl->second->next;

            while(curd != dl->second)
            {
                PList p = PList(curd->getPerson().getCapacity());
                while(p.getCapacity() != 0 && curp != pl->second)
                {
                    if (curp->getPerson().getCanBus()) addNodeBack(curp, "misc");

                    else p.addNode(curp);
                    
                }

                Node * temp = curd;
                curd = curd->next;
                // publish and remove driver if full
                if (p.getCapacity() == 0)
                {
                    pub.publish(curd);

                    p.~PList();
                    delete curd;

                }
                
            }





        }

        // Reassign leftover nodes
        Node * curr = pl->second->next;
        DNode * curd = dl->second->next;
        while(curr != pl->second)
        {
            if (curr->getPerson().getGender() == "male")
            {
                removeNode(curr);
                addNode(curr, "male");
            }

            else if (curr->getPerson().getGender() == "female") 
            {
                removeNode(curr);
                addNode(curr, "female");
            }

            else addNode(curr, "misc");
             {
                removeNode(curr);
                addNode(curr, "misc");
            }
        }




}

void Planner::sortgen(string gen)
{
    
    auto dl = driverlist.find(gen);
    auto pl = passengerlist.find(gen);

    Node * curr = pl->second->next;

    while(curr != pl->second)
    {
        for(string grp : grouplist)
        {}
        curr = curr->next;
    }


}

void Planner::sortmisc()
{

}

void Planner::addNodeBack(Node * n, string destination)
{
    if (passengerlist.count(destination) != 0) 
    {
        Node * at = passengerlist.find(destination)->second;
        
        Node * temp = at->prev;
        at->prev = n;
        n->next = at;
        n->prev = temp;
        temp->next = n;
    }
}

void Planner::addNode(Node * n, string destination)
{
     if (passengerlist.count(destination) != 0) 
    {
        Node * at = passengerlist.find(destination)->second;
        
        Node * temp = at->next;
        at->next = n;
        n->prev = at;
        n->next = temp;

        temp->prev = n;
    }
}

void Planner::addNode(DNode * n, string destination)
{
    if (driverlist.count(destination) != 0) 
    {
        DNode * at = driverlist.find(destination)->second;
        
        DNode * temp = at->next;
        at->next = n;
        n->prev = at;
        n->next = temp;

        temp->prev = n;
    }
}

void Planner::removeNode(Node * n)
{
    Node * temp = n->prev;
    n->prev->next = n->next;
    n->next->prev = temp;

    n->next = NULL;
    n->prev = NULL;
}




unordered_map<string, Node *> Planner::getPList()
{
    return passengerlist;
}

unordered_map<string, DNode *> Planner::getDList()
{
    return driverlist;
}

vector<string> Planner:: getGList()
{
    return grouplist;
}

void Planner::addNodeBackPub(Node * n, string destination)
{
    addNodeBack(n, destination);
}

void Planner::addNodePub(Node * n, string destination)
{
    addNode(n, destination);
}
void Planner::removeNodePub(Node * n)
{
    removeNode(n);
}