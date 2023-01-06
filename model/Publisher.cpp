
#include "Publisher.h"



Publisher::Publisher(){}


void Publisher::publish(DNode * m)
{
    cout << "________" << endl;
    Driver d = m->getPerson();
    PList p = *d.getplist();

    cout << d.getName() << " " << d.getGroup() << " " << d.getPhone() << endl;
    cout << "drives: " << endl;
    Node * curr = p.getSentinel()->next;

    while (curr)
    {
        Person per = curr->getPerson();
        cout << " - " << per.getName() << " " << per.getGroup() << " " << per.getPhone() << endl;
    }

    cout << "with " << p.getCapacity() << " seats remaining" << endl;

}

void Publisher::publishextra(Node * n)
{
    cout << "________" << endl;
    cout << "There were not enough rides to assign the following to a ride:" << endl;

    Node * curr = n;

    while(curr) 
    {
         Person per = curr->getPerson();
        cout << " - " << per.getName() << " " << per.getGroup() << " " << per.getPhone() << endl;
    }

}
