#include "Mset.h"

int main()
{
    Mset<int> v;

    v.pushback(3);
    v.pushback(2);
    v.pushback(7);
    v.pushback(13);
    v.pushback(21);
    v.pushback(9);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int size = v.size();

    v.pushback(7);
    v.pushback(12);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    v.insert(3, 9);
    v.insert(4, 22);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}