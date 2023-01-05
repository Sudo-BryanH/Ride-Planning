#include "Planner.h"






Planner::Planner(unordered_map<string, DNode * > & driverlist, unordered_map<string, Node * > & passengerlist, vector<string> & grouplist)
{


}

void Planner::planride()
{
    for(string g : grouplist)
    {
        if (driverlist.find(g) != driverlist.end() && passengerlist.find(g) == passengerlist.find(g))
        {

        }
        else if (driverlist.find(g) == driverlist.end() && passengerlist.find(g) != passengerlist.find(g))
        {

        }
        else
        {

        }
    }

}