//
// Created by Angry Bird on 4/4/18.
//
#ifndef PROJECT_2_PROJ2_H
#define PROJECT_2_PROJ2_H
#include <iostream>

using std::string;
const int size = 5;

template <class itemType>
class Department {
private:

    itemType name;
    string employeeID[size];
    itemType employeeSalary[size];
    int itemCount;
    int maxItem;

    bool isFull();
    bool isEmpty() const;


public:

    Department(const itemType & newItem);
    Department();
    ~Department();
    void setID(const itemType & newItem);
    string getID() const;
    void setSalary(const itemType & newItem);
    float getSalary() const;
    int getIndexOf(const itemType & item) const;
    bool add();
    bool remove();
    bool clear();
};
#endif //PROJECT_2_PROJ2_H