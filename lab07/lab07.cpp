//Jesus Medina
//July 25, 2019
//lab07.cpp

#include "Mtree.h"
#include <time.h>
#include <cstdlib>

int main()
{
    clock_t start, finish;
    srand(time(NULL));
    Mtree<int> t;
    Mtree<int> t2;
    int n = 0;
    cout << "Enter size of input :";
    cin >> n;
    for (int i = 0; i < n; i++)
        t.add(rand());

    t2.add(4);
    t2.add(5);
    t2.add(1);
    t2.add(19);
    t2.add(12);
    t2.add(7);

    start = clock();
    vector<int> v = t.inorder();
    vector<int> v2 = t2.douborder();
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    finish = clock();
    cout << "time= " << finish - start;
}