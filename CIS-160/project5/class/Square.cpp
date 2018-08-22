#include <iostream>

#include "Square.h"

using namespace std;

void Square::setside(int s)
{
    side = s;
}

int Square::getperimeter()
{
 return side * 4;   
}

