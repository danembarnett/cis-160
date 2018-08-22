//
// Created by Angry Bird on 4/4/18.
//
#include <iostream>
#include "proj2.h"

template <class itemType>
bool Department<itemType>::isFull()
{
    if(itemCount >= maxItem)
        return false;
    else
    {
        return true;
    }

}

template <class itemType>
bool Department<itemType>::isEmpty() const
{
    return itemCount == 0;
}


template <class itemType>
Department <itemType>::Department(const itemType & newItem) {
    this->name = newItem;
    itemCount = 0;
    maxItem = size;
}

template <class itemType>
Department<itemType>::Department(){
    std::cout << "\nPlease enter course ID : ";
    std::getline(std::cin, this->name);
}

template <class itemType>
Department<itemType>::~Department() {}

template <class itemType>
void Department<itemType>::setID(const itemType & newItem)
{
    employeeID[itemCount] = newItem;
}

template <class itemType>
string Department<itemType>::getID() const
{
    return employeeID[itemCount];
}

template <class itemType>
void Department<itemType>::setSalary(const itemType & newItem)
{
    employeeSalary[itemCount] = newItem;
}

template <class itemType>
float Department <itemType>::getSalary() const
{
    return employeeSalary[itemCount];
}

template <class itemType>
int Department <itemType>::getIndexOf(const itemType & item) const
{
    bool indexFound = false;
    int result = -1;
    int searchIndex = 0;

    while(!indexFound && (searchIndex < itemCount))
    {
        if(employeeID[searchIndex] == item)
        {
            indexFound = true;
            result = searchIndex;
        }
        else
        {
            searchIndex++;
        }
    }
    return result;
}

template <class itemType>
bool Department<itemType>::add()
{
    string newID;
    itemType newSalary;

    bool spaceAvailable = isFull();
    if(spaceAvailable)
    {
        std::cout << "\nPlease Enter new ID : "; std::cin >> newID;
        std::cout << "\nPlease Enter the Salary for this ID : "; std::cin >> newSalary;

        employeeID[itemCount] = newID;
        employeeSalary[itemCount] = newSalary;
        itemCount++;
    }
    return spaceAvailable;
}

template <class itemType>
bool Department<itemType>::remove() 
{
    string id;

    std::cout << "\nEnter the ID you want to remove : ";
    std::cin >> id;

    int locateTheIndex = getIndexOf(id);

    bool itemCanBeRemoved = !isEmpty() && (locateTheIndex > -1);
    if (itemCanBeRemoved)
    {
        itemCount--;
        employeeID[locateTheIndex] = employeeID[itemCount];
        employeeSalary[locateTheIndex] = employeeSalary[itemCount];

    }
    return itemCanBeRemoved;  
}

template <class itemType>
bool Department<itemType>::clear()
{
    std::cout << "------------------------------------------\n";
    std::cout << "|  Employee ID  |      Employee Salary    \n";
    std::cout << "------------------------------------------\n";

    do 
    {
        std::cout << std::setw(3) << itemCount << ". " << employeeID[itemCount-1] << 
        "\t\t" << std::setw(4) << "$" << employeeSalary[itemCount-1] << std::endl;
        itemCount--;
    }

    while(itemCount >= 1);

    std::cout << "------------------------------------------\n";

    itemCount = 0;

    return true;

}