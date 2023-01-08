#include "Planner.h"






Planner::Planner(unordered_map<string, DNode * > & dmap, unordered_map<string, Node * > & pmap, vector<string> & glist) 
{
    pub = Publisher();
    dmap = dmap;
    pmap = pmap;
    grouplist = glist;

}

void Planner::planride()
{
    for(string g : grouplist)
    {
        DNode * dl;
        Node * pl;
        try
        {
            dl = dmap.at(g); 
        } 
        catch (std::out_of_range)
        {
            dl = NULL;
        }

        try
        {
            pl = pmap.at(g); 
        } 
        catch (std::out_of_range)
        {
            pl = NULL;
        }
        // auto pl = pmap.find(g);
        sort(dl, pl);
    }

    sortgen();

    sortmisc();

}

// void Planner::sort(unordered_map<string, DNode *>::iterator & dl, unordered_map<string, Node *>::iterator & pl)
void Planner::sort(DNode * dl, Node* pl)
{

    //reminder to use pmap's regular add node fn

        // if (dl != dmap.end() && pl == pmap.end())
        // {
          
        // }
        // else if (dl == dmap.end() && pl != pmap.end())
        // {
            
        // }
        // else
        if (dl && pl)
        {
            Node * curp = pl->next;
            DNode * curd = dl->next;

            while(curd != dl)
            {
                PList p = PList(curd->getPerson().getCapacity());
                while(p.getCapacity() != 0 && curp != pl)
                {
                    if (curp->getPerson().getCanBus()) addNodeBack(curp, "misc");

                    else p.addNode(curp);
                    curd = curd->next;
                }

                Node * temp = curd;
                // curd = curd->next;
                // publish and remove driver if full
                //TODO add plist to curd
                if (p.getCapacity() == 0)
                {
                    pub.publish(curd);

                    p.~PList();
                    delete curd;

                }
                
            }





        }

        // Reassign leftover nodes
        Node * curr = pl->next;
        DNode * curd = dl->next;
        while(curr != pl)
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

void Planner::sortgen()
{
    
    for(auto it = dmap.cbegin(); it != dmap.cend(); it++)
    {
        DNode * dn = it->second->next;
        string gender = dn->getPerson().getGender();
        int cap = dn->getPerson().getplist()->getCapacity();

        Node * curr = pmap.at(gender)->next;

        PList p = PList(cap);
        while(p.getCapacity() != 0 && curr != pmap.at(gender))
        {
            p.addNode(curr);
            curr = curr->next;
        }

    }


}

void Planner::sortmisc()
{

}

void Planner::addNodeBack(Node * n, string destination)
{
    if (pmap.count(destination) != 0) 
    {
        Node * at = pmap.find(destination)->second;
        
        Node * temp = at->prev;
        at->prev = n;
        n->next = at;
        n->prev = temp;
        temp->next = n;
    }
}

void Planner::addNode(Node * n, string destination)
{
     if (pmap.count(destination) != 0) 
    {
        Node * at = pmap.find(destination)->second;
        
        Node * temp = at->next;
        at->next = n;
        n->prev = at;
        n->next = temp;

        temp->prev = n;
    }
}

void Planner::addNode(DNode * n, string destination)
{
    if (dmap.count(destination) != 0) 
    {
        DNode * at = dmap.find(destination)->second;
        
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




unordered_map<string, Node *> Planner::getpmap()
{
    return pmap;
}

unordered_map<string, DNode *> Planner::getdmap()
{
    return dmap;
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