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

        // deletes any groups that are now empty. makes it asymptotically easier to determine if there remains any member in a group
        checkEraseDmap(dl, g);
        checkErasePmap(pl, g);
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
                PList * p = new PList(curd->getPerson().getCapacity());
                while(p->getCapacity() != 0 && curp != pl)
                {
                    Node * temp = curp->next;
                    if (curp->getPerson().getCanBus()) addNodeBack(curp, "misc");

                    else p->addNode(curp); // TODO may have to update curp pointer
                    curp = temp;
                }

                Node * temp = curd;
                curd = curd->next;
                // publish and remove driver if full


                dl->getPerson().setplist(p);
                canPublish(curd);
                
            }





        }

        // Reassign leftover nodes
        Node * curr = pl->next;
       
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
    // Goes through each remaining driver, takes passengers from pmap.
    for(auto it = dmap.cbegin(); it != dmap.cend(); it++)
    {
        if (it->first != "misc"){
            
            
            DNode * dn = it->second->next;
            while(dn != it->second)
            {
                Driver dr = dn->getPerson();
                string gender = dr.getGender();
                int cap = dr.getplist()->getCapacity();


                Node * curr = pmap.at(gender)->next;
                
                PList * p;
                if (dr.getplist() == NULL)
                {
                    p = new PList(cap);
                    dr.setplist(p);
                }
                else
                {
                    p = dr.getplist();
                }

                // while car isn't full and there are still people of that gender to get, add them to plist.
                while(p->getCapacity() != 0 && curr != pmap.at(gender))
                {

                    if (curr->getPerson().getCanBus()) addNodeBack(curr, "misc");
                    p->addNode(curr);
                    curr = curr->next;
                }

                // publish and delete
                DNode * temp = dn;
                dn = dn->next;

                canPublish(temp);
                checkEraseDmap(temp, gender);
                
            }

        }
    }

    // reassign leftover passengers to misc of high priority
    Node * m = pmap.at("male")->next;
    Node * f = pmap.at("female")->next;

    while(m != pmap.at("male"))
    {
        addNode(m, "misc");
        
    }

    while(f != pmap.at("female"))
    {
        addNode(m, "misc");
        
    }

}

void Planner::sortmisc()
{
    Node * curr = pmap.at("misc")->next;

    while(curr != pmap.at("misc"))
    {
        Person p = curr->getPerson();

        //if (p.getGroup() != )

        curr = curr->next;
    }
}



void Planner::addNodeBack(Node * n, string destination)
{
    if (pmap.count(destination) != 0) 
    {
        Node * at = pmap.at(destination);
        
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

void Planner::canPublish(DNode * dn)
{
    PList * p = dn->getPerson().getplist();
    if (p->getCapacity() == 0)
    {
        pub.publish(dn);

        p->~PList();
        delete dn;
    }
}

void Planner::checkEraseDmap(DNode * dl, string g)
{


    if (dl->next == dl)
    {
        delete dl;
        dmap.erase(g); 
    }
}

void Planner::checkErasePmap(Node * pl, string g)
{
        if (pl->next == pl)
    {
        delete pl;
        pmap.erase(g);
    }
}