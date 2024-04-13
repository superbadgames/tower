#include "pch.h"
#include "Test/HelloWorld.h"

using namespace Tower_Test;

HelloWorld::HelloWorld(void) :
    _name(""),
    _age(0)
{

}


HelloWorld::~HelloWorld(void)
{

}


void HelloWorld::SetName(string name)
{
    _name = name;
}

string HelloWorld::GetName(void) const
{
    return _name;
}
