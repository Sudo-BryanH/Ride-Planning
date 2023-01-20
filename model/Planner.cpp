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
    // TODO need to print out everything whether full or not


        // deletes any groups that are now empty. makes it asymptotically easier to determine if there remains any member in a group

    }

    sortgen();

    // sortmisc();

    for (auto it = dmap.cbegin(); it != dmap.cend(); it++)
    {
        DNode * base = it->second;
        DNode * curr = base->next;
        cout << __LINE__ << endl;
        while (curr != base) pub.publish(curr);
        
    }

}



// void Planner::sort(unordered_map<string, DNode *>::iterator & dl, unordered_map<string, Node *>::iterator & pl)
void Planner::sort(DNode * dl, Node* pl)
{
    cout << __LINE__ << endl;
        string group = pl->next->getPerson().getGroup();
     cout << __LINE__ << endl;
     cout << pl->next->getPerson().getName() << " began" << endl;
        if (dl && pl)
        {

            DNode * curd = dl->next;
            cout << __LINE__ << endl;
            while(curd != dl)
            {
                DNode * tempnext = curd->next;
                cout << __LINE__ << endl;
                //PList * p = new PList(curd->getPerson().getCapacity());
                PList * plist = curd->getPerson().getplist();
                assignOrReassign(pl, plist);
//cout << "sorting " << pmap.count(group) << endl;

                cout << __LINE__ << endl;
                bool b = canPublish(curd);
                curd = tempnext;
                cout << __LINE__ << endl;
            }

        }

        // Reassign leftover nodes
        Node * curr = pl->next;
      //cout << "sorting " << pmap.count(group) << endl;
      cout << __LINE__ << endl;
        while(curr != pl)
        {
            
            Node * tempnext = curr->next;
            if (curr->getPerson().getGender() == "male")
            {
                removeNode(curr);
                addNode(curr, "male");
            } else if (curr->getPerson().getGender() == "female") 
            {
                removeNode(curr);
                addNode(curr, "female");
            } else 
            {
                removeNode(curr);
                addNode(curr, "misc");
            }
            curr = tempnext;
        }
        //cout << "sorting " << pmap.count(group) << endl;
        cout << __LINE__ << endl;
        try{
            checkEraseDmap(dl, group);
        } catch (std::out_of_range)
        {}
        try{
            checkErasePmap(pl, group);
        } catch (std::out_of_range)
        {}
        cout << pl->next->getPerson().getName() << "  done" << endl;
}

void Planner::assignOrReassign(Node * sen, PList * p)
{
    Node * curr = sen->next;

    while(curr && p->getCapacity() > 0 && curr != sen)
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
}


void Planner::assignGen(DNode * dn)
{
    DNode * base = dn;

    
    dn = dn->next;

    
    while(dn != base)
    {

        //cout << __LINE__ << endl;
        Driver dr = dn->getPerson();
        string gender = dr.getGender();
        int cap = dr.getplist()->getCapacity();

        //cout << __LINE__ << endl;
        Node * base = pmap.at(gender);
        Node * curr = base->next;
        //cout << __LINE__ << endl;
        PList * p = dr.getplist();

        //cout << __LINE__ << endl;
        // while car isn't full and there are still people of that gender to get, add them to plist. if they canBus, push to misc
        assignOrReassign(base, p);

        // publish and delete
        DNode * temp = dn;
        dn = dn->next;
        //cout << __LINE__ << endl;
        bool b = canPublish(temp);

        try{
            checkEraseDmap(dmap.at(dn->getPerson().getGroup()),dn->getPerson().getGroup()); 
        } catch (std::out_of_range)
        {}// at not found
        //cout << __LINE__ << endl;
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
    for(auto it = dmap.cbegin(); it != dmap.cend();  it++)
    {
        //cout << __LINE__ << endl;
        if (it->first != "misc" && it->first != "female" && it->first != "male"){
            
            dn = it->second;
            assignGen(dn);

        }
       
        //cout << __LINE__ << endl;
    }

    // reassign leftover passengers to misc of high priority
    Node * m = pmap.at("male")->next;
    Node * f = pmap.at("female")->next;
    Node * tempnext;
    while(m != pmap.at("male"))
    {
        tempnext = m->next;
        removeNode(m);
        addNode(m, "misc");
        m = tempnext;
        
    }

    while(f != pmap.at("female"))
    {
        tempnext = f->next;
        removeNode(f);
        addNode(m, "misc");
        f = tempnext;
        
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

  //  cout << __LINE__ << endl;
    if (dl != NULL && dl->next == dl)
    {   
       // cout << __LINE__ << endl;
        delete dl;
        dmap.erase(dmap.find(g)); 
    }
}

void Planner::checkErasePmap(Node * pl, string g)
{
   // cout << __LINE__ << endl;
    if (pl != NULL &&pl->next == pl)
    {
        delete pl;
        //cout << pmap.count(g) << endl;
        pmap.erase(pmap.find(g));

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

void Planner::sortgenPub()
{
    sortgen();
}

void Planner::sortPub(DNode * d, Node * n)
{
    cout << __LINE__ << endl;
    sort(d, n);
}