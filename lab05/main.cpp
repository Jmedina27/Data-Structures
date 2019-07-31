#include "Mlist.h"

int main()
{
    Mlist<int> li;
    li.add(10);
    li.add(20);
    li.add(30);
    li.add(40);
    li.add(50);
    li.add(60);

    for (int i = 0; i < li.size(); i++)
    {
        cout << li[i] << " ";
    }
    cout << endl;

    li.insert(3, 35);
    for (int i = 0; i < li.size(); i++)
    {
        cout << li[i] << " ";
    }
    cout << endl;

    li.erase(3);
    for (int i = 0; i < li.size(); i++)
    {
        cout << li[i] << " ";
    }
    cout << endl;
}
