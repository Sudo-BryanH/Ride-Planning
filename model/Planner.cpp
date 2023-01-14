#include "Planner.h"



Planner::Planner()
{
    pub = Publisher();
}


Planner::Planner(unordered_map<string, DNode * > & drmap, unordered_map<string, Node * > & pamap, vector<string> & glist) 
{
    pub = Publisher();
    dmap = drmap;
    pmap = pamap;
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
                //PList * p = new PList(curd->getPerson().getCapacity());
                PList * p = dl->getPerson().getplist();
                while(p->getCapacity() != 0 && curp != pl)
                {
                    Node * temp = curp->next;

                    removeNode(curp);
                    if (curp->getPerson().getCanBus()) 
                    {
                        addNodeBack(curp, "misc");
                    }
                    //remove the node

                    else
                    { 
                        
                        p->addNode(curp);
                        
                    }
                    curp = temp;
                }

                Node * temp = curd;
                curd = curd->next;
                // publish and remove driver if full


                dl->getPerson().setplist(p);
                bool b = canPublish(curd);
                
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


void Planner::assignGen(DNode * dn)
{
    DNode * base = dn;

    
    dn = dn->next;

    
    while(dn != base)
    {

   
        Driver dr = dn->getPerson();
        string gender = dr.getGender();
        int cap = dr.getplist()->getCapacity();


        Node * curr = pmap.at(gender)->next;
        
        PList * p = dr.getplist();


        // while car isn't full and there are still people of that gender to get, add them to plist. if they canBus, push to misc
        
        while(curr && p->getCapacity() > 0 && curr != pmap.at(gender))
        {
            Node * tempnext = curr->next;
            removeNode(curr);
            
            if (curr->getPerson().getCanBus()) 
            {

                //cout << "IF RAN " << curr->getPerson().getName() << endl;
                addNodeBack(curr, "misc");
            }

            
            else 
            {
                //cout << "ELSE RAN " << curr->getPerson().getName() << endl;
                p->addNode(curr);
            }
            
            curr = tempnext;
        }

        // publish and delete
        DNode * temp = dn;
        dn = dn->next;

        bool b = canPublish(temp);
        checkEraseDmap(temp, gender);
        
    }
}

void Planner::sortgen()
{
    // Goes through each remaining driver, takes passengers from pmap.
    // TODO make it so it goes through gender first ebfore looping the groups
    // Loop through driver gender groups
    DNode * dn = dmap.at("male");
    assignGen(dn);
    dn = dmap.at("female");
    assignGen(dn);

    // Loop through driver groups
    for(auto it = dmap.cbegin(); it != dmap.cend(); it++)
    {
        if (it->first != "misc"){
            
            dn = it->second;
            assignGen(dn);

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
    //cout << "REMOVE" << endl;
    
    Node * temp = n->prev;
    //cout << __LINE__ << endl; 
    n->prev->next = n->next;
    //cout << __LINE__ << endl; //unseen
    n->next->prev = temp;
    //cout << __LINE__ << endl;

    n->next = NULL;
    //cout << __LINE__ << endl;
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

bool Planner::canPublish(DNode * dn)
{
    //cout << __LINE__ << endl;
    PList * p = dn->getPerson().getplist();
    
    //cout << __LINE__ << endl;
    if (p->getCapacity() == 0)
    {
        //cout << __LINE__ << endl;
        pub.publish(dn);
        //cout << __LINE__ << endl;
        //p->~PList();
        delete dn;
        //cout << __LINE__ << endl;
        return true;
    }
    return false;
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

void Planner::checkErasePmapPub(Node * pl, string group)
{
    checkErasePmap(pl, group);
}

bool Planner::canPublishPub(DNode * d)
{
    return canPublish(d);
}

void Planner::assignGenPub(DNode * d)
{
    assignGen(d);
}