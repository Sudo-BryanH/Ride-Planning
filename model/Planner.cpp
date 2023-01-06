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

        if (dl != driverlist.end() && pl == passengerlist.end())
        {
          
        }
        else if (dl == driverlist.end() && pl != passengerlist.end())
        {
            
        }
        else
        {
            Node * curp = pl->second;
            DNode * curd = dl->second;

            while(curd)
            {
                PList p = PList(curd->getPerson().getCapacity());
                while(p.getCapacity() != 0 && curp)
                {
                    p.addNode(curp);
                }
                curd = curd->next;
            }



        }


}