
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

    while (curr != p.getSentinel())
    {

        Person per = curr->getPerson();
        cout << " - " << per.getName() << " " << per.getGroup() << " " << per.getPhone() << endl;
        Node *temp = curr;
        curr = curr->next;
        
    }

    cout << "with " << p.getCapacity() << " seats remaining" << endl;
    
}

void Publisher::publishextra(Node * n)
{
    cout << "________" << endl;
    cout << "There were not enough rides to assign the following to a ride:" << endl;

    Node * curr = n->next;
    

    while(curr && curr != n) 
    {
        
        Person per = curr->getPerson();
        cout << " - " << per.getName() << " " << per.getGroup() << " " << per.getPhone() << endl;
        curr = curr->next;
        
    }
    

}
