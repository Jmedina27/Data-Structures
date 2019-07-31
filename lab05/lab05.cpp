//Jesus Medina
//July 18th, 2019
//lab05.cpp

#include "Mlist.h"

int main()
{
    //create a list of type int
    Mlist<int> ml = Mlist<int>();
    //add elements into the list
    ml.add(4);
    ml.add(5);
    ml.add(6);
    ml.add(7);
    ml.add(8);
    ml.add(9);
    ml.add(6);
    ml.add(10);

    //print out the list using iterators
    for (Mlist<int>::iterator it = ml.begin(); it != NULL; it = it->rptr)
    {
        cout << it->data << " ";
    }
    cout << endl;
    //delete all 6 in the list
    ml.del(6);
    //erase the value at the index 3
    //insert 13 at the index 4
    ml.erase(3);
    ml.insert(4, 13);
    //print the updated list
    for (Mlist<int>::iterator it = ml.begin(); it != NULL; it = it->rptr)
    {
        cout << it->data << " ";
    }

    //get the front and last of the list
    cout << endl;
    int front = ml.get_front();
    cout << "front is: " << front << endl;

    int last = ml.get_last();
    cout << "last is: " << last << endl;

    //return the size of the list
    int size = ml.size();
    cout << "size of the list is: " << size << endl;

    int index = ml[3];
    cout << "index at 3 is : " << index << endl;
}
