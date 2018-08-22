/**********************************************************
 * Name        : Louis Taveras                            *
 *             : Dane Barnett                             *
 * Class       : CIS 260 ME1                              *
 * Date        : May 7, 2018                              *
 * Program     : Project 3- Template Class                *
 * Description : A program that inputs data from a file   *
 *               into a template class that contains     *
 *               a a linked list that adds and remove data*
***********************************************************/


#include "MyList.h"
#include <fstream>
#include <cstdlib>

//converting string to int
int		toi(char *str)
{
    int res;

    res = 0;
    while (str && *str == ' ')
        str++;
    while (str && *str >= '0' && *str <= '9') {
        res = res * 10 + *str - '0';
        *str = ' ';
        str++;
    }
    return (res);
}

//converting string to double
double	tod(char *str)
{
    double	res;
    int		n;

    res = 0.0;
    while (str && *str == ' ')
        str++;
    while (str && *str >= '0' && *str <= '9') {
        res = res * 10 + *str - '0';
        *str = ' ';
        str++;
    }
    if (*str == '.')
    {
        *str = ' ';
        str++;
    }
    n = 10;
    while (str && *str >= '0' && *str <= '9') {
        res = res + (double)(*str - '0') / n;
        *str = ' ';
        str++;
        n *= 10;
    }
    return (res);
}

int main()
{
    //declaration of myList
    myList<int> *lst = new myList<int>;
    myList<double> *lst2 = new myList<double>;

    //variable declation
    char		buf[3][128];
    ifstream	f1, f2;
    int			i;

    //reading data1.txt
    cout << "READING DATA1.TXT ..." << endl;
    //reading, adding data to int list
    i = 0;
    f1.open("data1.txt", ios_base::in);
    while (f1.getline(buf[i++], 128)) {
        if (i % 3 == 0)	{
            lst->Add(toi(buf[0]), buf[1], toi(buf[2]), toi(buf[2]));
            i = 0;
        }
    }
    f1.close();
    cout << endl;

    //reading data2.txt
    cout << "READING DATA2.TXT ..." << endl;
    //reading, adding data to double list
    i = 0;
    f2.open("data2.txt", ios_base::in);
    while (f2.getline(buf[i++], 128)) {
        if (i % 3 == 0) {
            lst2->Add(toi(buf[0]), buf[1], tod(buf[2]), tod(buf[2]));
            i = 0;
        }
    }
    f2.close();
    cout << endl;

    cout << "### TEST 1.1 ###" << endl;
    //correct peek by id
    lst->peek(24085);
    //incorrect peek by id
    lst->peek(123);

    cout << "### TEST 1.2 ###" << endl;
    //correct peek by name
    lst2->peek("De la Cruz, Edward");
    //incorrect peek by name
    lst2->peek("This is not a name");
    cout << endl;

    cout << "### TEST 2.1 ###" << endl;
    //print lst
    lst->print();
    cout << "### TEST 2.1a ###" << endl;
    //correct find and Remove
    lst->Remove(lst->find("ATamimi, Trevone"));
    lst->print(lst->find("ATamimi, Trevone"));
    cout << "### TEST 2.1b ###" << endl;
    lst->print();
    cout << "### TEST 2.2 ###" << endl;
    //incorrect find and Remove
    lst->Remove(lst->find(156));
    lst->print(lst->find(156));
    cout << "### TEST 2.2a ###" << endl;
    lst->print();
    cout << endl;

    cout << "### TEST 3 ###" << endl;
    //clear list
    lst->Clear();
    //clear same list
    lst->Clear();
    //clear list 2
    lst2->Clear();
    lst->~myList();
    lst2->~myList();
    delete lst;
    delete lst2;
    return (0);
}
