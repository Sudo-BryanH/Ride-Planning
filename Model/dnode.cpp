
#include "dnode.h"

dnode::dnode() : node(d) {}

dnode::dnode(driver d) : d(d), node(d)
{

}

driver dnode::getDriver()
{
    return d;
}