//Jesus Medina
//005172852
//sort.cpp

#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;

//selection sort algorithm
void selection_sort(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

//bubble sort algorithm
void bubble_sort(vector<int> &v)
{
    for (int i = v.size(); i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[j] > v[i])
            {
                swap(v[j], v[i + 1]);
            }
        }
    }
}


int main()
{
    clock_t start, finish;
    srand(time(NULL));

    vector<int> v;
    int n = 0;

    cout << "Enter the size of the vector : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        v.push_back(rand());
    }

    vector<int> v2 = v;

    //bubblesort
    start = clock();
    bubble_sort(v);
    finish = clock();
    cout << "cpu time for bubble sort = " << finish - start << endl;

    //selectionsort
    start = clock();
    selection_sort(v2);
    finish = clock();
    cout << "cpu time for selection sort = " << finish - start << endl;
}
