#include "MyList.h"

/*
 * *************myList()*****************
 * This constructor accepts a sets the a
 * new linked list to a null pointer.
 *
 * @parameter : None.
 *
 * @return : Does not return.
 */
template<typename T1>
myList<T1>::myList()
{
    this->next = nullptr;
}

/*
 * *************~myList()*****************
 * This is a destructor
 *
 * @parameter : None.
 *
 * @return : Does not return.
 */
template<typename T1>
myList<T1>::~myList()
{
}

/*
 * *************isEmpty()*****************
 * This is a method that returns a bool
 * depending on if the linked list count
 * is empty or not.
 *
 * @parameter : None.
 *
 * @return : this function returns true if
 *           the next item in the linked
 *           list is null. Otherwise it
 *           returns false.
 */
template<typename T1>
bool myList<T1>::isEmpty()
{
    return (this->next == nullptr) ? true : false;
}

/*
 * *************Add()*****************
 * This method adds data to the front of
 * the linked list.
 *
 * @parameter : this method accepts four
 *              parameter including id(int)
 *              name(string), rate(T1),
 *              hours(T1).
 *
 * @return : Does not return.
 */
template<typename T1>
void myList<T1>::Add(int id, string name, T1 rate, T1 hours)
{
    myList<T1>	*cur;
    myList<T1>	*tmp;

    cur = this;
    if (isEmpty()) {
        cur->next = new myList<T1>;
        cur = cur->next;
        cur->id = id;
        cur->name = name;
        cur->hours = hours;
        cur->rate = rate;
        cur->next = nullptr;
    }
    else {
        while (cur->next && cur->next->id > id)
            cur = cur->next;
        tmp = new myList<T1>;
        tmp->id = id;
        tmp->name = name;
        tmp->hours = hours;
        tmp->rate = rate;
        tmp->next = cur->next;
        cur->next = tmp;
    }
}

/*
 * *************find()*****************
 * This is a method that finds the id
 * and returns it's current location
 * of the node.
 *
 * @parameter : id(int)
 *
 * @return : return the current mylist
 *           Node.
 */
template<typename T1>
myList<T1>* myList<T1>::find(int id)
{
    myList<T1>	*cur;

    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    cur = this->next;
    while (cur && cur->id != id)
        cur = cur->next;
    return (cur);
}

/*
 * *************find()*****************
 * This is a method that finds the name
 * and returns it's current location
 * of the node.
 *
 * @parameter : name(string)
 *
 * @return : return the current mylist
 *           Node.
 */
template<typename T1>
myList<T1>* myList<T1>::find(string name)
{
    myList<T1>	*cur;

    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    cur = this->next;
    while (cur && cur->name != name)
        cur = cur->next;
    return (cur);
}

/*
 * *************peek()*****************
 * This method prints the current node
 * in the list if the linkedlist is not
 * equal to null.
 *
 * @parameter : id(int)
 *
 * @return : Does not return.
 */
template<typename T1>
void myList<T1>::peek(int id)
{
    myList<T1>	*cur;

    cur = find(id);
    if (cur == nullptr)
        cout << "There is no person with id = " << id << " in the list!" << endl;
    else
        print(cur);
}

/*
 * *************peek()*****************
 * This is a method that finds the name
 * and returns it's current location
 * of the node.
 *
 * @parameter : name(string)
 *
 * @return : return the current myList
 *           Node.
 */
template<typename T1>
void myList<T1>::peek(string name)
{
    myList<T1>	*cur;

    cur = find(name);
    if (cur == nullptr)
        cout << "There is no person with name = \""<< name << "\" in the list!" << endl;
    else
        print(cur);
}

/*
 * *************Remove()*****************
 * This is a method that finds the target
 * list, remove the current list and
 * connects the next to the last.
 *
 * @parameter : targ(myList<T1> *)
 *
 * @return : return the linked list
 */
template<typename T1>
bool myList<T1>::Remove(myList<T1>* targ)
{
    myList<T1>	*cur;
    myList<T1>	*tmp;

    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return false;
    }
    if (targ == nullptr)
        return false;
    cur = find(targ->id);
    if (cur == nullptr)
        return false;
    if (cur->next == nullptr) {
        cur->~myList();
        delete cur;
        this->next = nullptr;
        return true;
    }
    tmp = cur->next;
    cur->id = tmp->id;
    cur->name = tmp->name;
    cur->hours = tmp->hours;
    cur->rate = tmp->rate;
    cur->next = tmp->next;
    tmp->~myList();
    delete	tmp;
    return true;
}

/*
 * *************get_id()*****************
 * This is a method returns the id in the
 * current linked list.
 *
 * @parameter : targ(myList<T1> *)
 *
 * @return : return the current mylist
 *           Node.
 */
template<typename T1>
int myList<T1>::get_id(myList<T1>* targ)
{
    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return 0;
    }
    if (targ == nullptr)
        return (-1);
    return targ->id;
}

/*
 * *************get_name()*****************
 * This is a method returns the name in the
 * current linked list.
 *
 * @parameter : targ(myList<T1> *)
 *
 * @return : return the current name which
 *           is a string in the linked list.
 */

template<typename T1>
string myList<T1>::get_name(myList<T1>* targ)
{
    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return nullptr;
    }
    if (targ == nullptr)
        return nullptr;
    return targ->name;
}

/*
 * *************get_hours()*****************
 * This is a method returns the hours in the
 * current linked list.
 *
 * @parameter : targ(myList<T1> *)
 *
 * @return : return the current T1 in the
 *           linked list.
 */
template<typename T1>
T1 myList<T1>::get_hours(myList<T1>* targ)
{
    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return 0;
    }
    if (targ == nullptr)
        return (-1);
    return targ->hours;
}

/*
 * *************get_rate()*****************
 * This is a method returns the rate in the
 * current linked list.
 *
 * @parameter : targ(myList<T1> *)
 *
 * @return : return the current mylist
 *           Node.
 */
template<typename T1>
T1 myList<T1>::get_rate(myList<T1>* targ)
{
    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return 0;
    }
    if (targ == nullptr)
        return (-1);
    return targ->rate;
}

/*
 * *************print()*****************
 * This is a method prints all the node
 * in the linked list
 *
 * @parameter : None.
 *
 * @return : Does not return.
 */
template<typename T1>
void myList<T1>::print()
{
    myList<T1>	*cur;

    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return;
    }
    cur = this->next;
    while (cur)
    {
        print(cur);
        cur = cur->next;
    }
}

/*
 * *************print()*****************
 * This is a method prints the target node
 * in the linked list.
 *
 * @parameter : targ(myList<T1>*).
 *
 * @return : Does not return.
 */
template<typename T1>
void myList<T1>::print(myList<T1>* targ)
{
    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return;
    }
    if (targ == nullptr) {
        cout << "Can not print! Target is not in list!" << endl;
        return;
    }
    cout.width(10);
    cout << targ->id;
    cout.width(40);
    cout << targ->name;
    cout.width(10);
    cout << targ->hours;
    cout.width(10);
    cout << targ->rate << endl;
}

/*
 * *************print()*****************
 * This is a method removes all the node
 * in the linked list
 *
 * @parameter : None.
 *
 * @return : Does not return.
 */
template<typename T1>
void myList<T1>::Clear()
{
    myList<T1>	*cur;

    if (this->isEmpty()) {
        cout << "List is empty!" << endl;
        return;
    }
    print();
    cur = this->next;
    while (Remove(cur)) {};
}

template class myList<int>;
template class myList<double>;
template class myList<float>;
