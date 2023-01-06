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

    auto dl = driverlist.find("male");
    auto pl = passengerlist.find("male");


    auto dl = driverlist.find("female");
    auto pl = passengerlist.find("female");


    auto dl = driverlist.find("misc");
    auto pl = passengerlist.find("misc");



}

void Planner::sort(unordered_map<string, DNode *>::iterator dl, unordered_map<string, Node *>::iterator pl)
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
                while(p.getCapacity() != 0 && curp != pl->second);
                {
                    p.addNode(curp);
                    
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
        while(curr != pl->second)
        {
            if (curr->getPerson().getGender() == "male")
            {

            } 
            else if (curr->getPerson().getGender() == "female")
            {

            }
            else
            {

            }
        }




}