//
// Created by Angry Bird on 5/6/18.
//

#ifndef LOUISFINAL_MYLIST_H
#define LOUISFINAL_MYLIST_H

#include <string>
#include <iostream>

using namespace std;

template <typename T1>
class myList
{
private:
    int			id;
    string		name;
    T1			hours;
    T1			rate;
    myList<T1>	*next;
public:
    myList<T1>();
    ~myList<T1>();
    bool isEmpty();
    void Add(int id, string name, T1 rate, T1 hours);
    myList<T1> *find(int id);
    myList<T1> *find(string name);
    void peek(int id);
    void peek(string name);
    bool Remove(myList<T1> *targ);
    int	get_id(myList<T1> *targ);
    string get_name(myList<T1> *targ);
    T1 get_hours(myList<T1> *targ);
    T1 get_rate(myList<T1> *targ);
    void print();
    void print(myList<T1> *targ);
    void Clear();
};


#endif //LOUISFINAL_MYLIST_H
