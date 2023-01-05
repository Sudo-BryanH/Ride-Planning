
#include "Publisher.h"



Publisher::Publisher(){}


void Publisher::Publish(DNode * m)
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

    cout << "with " << d.getCapacity() << " seats remaining" << endl;

}
