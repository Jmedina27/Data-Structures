// Jesus Medina
// 005172852
// July 9th, 2019
//PQ.h

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

template <typename T>
class PQ
{
public:
    PQ();
    PQ(vector<T> n);
    T get_size();
    T get_front();
    void print();
    void push(T x);
    void pop();

private:
    vector<T> v;
    int size;
    //selection sort algorithm
    void selection_sort(vector<T> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                if (v[i] > v[j])
                {
                    swap(v[i], v[j]);
                }
            }
        }
    }
};

//default constructor with mo parameter
template <typename T>
PQ<T>::PQ()
{
    size = 0;
}

//constructor with parameter of a queue n
template <typename T>
PQ<T>::PQ(vector<T> n)
{
    //push all elements in vector n into vector v
    v = n;
    size = n.size();
    //sort the queue v in nondecresing order
    selection_sort(v);
}

//return the size of the queue
template <typename T>
T PQ<T>::get_size()
{
    return size;
}

//return the front of the queue
template <typename T>
T PQ<T>::get_front()
{
    return v[0];
}

//print all elements in the queue
template <typename T>
void PQ<T>::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

//add an elements into the queue
template <typename T>
void PQ<T>::push(T x)
{
    v.push_back(x);
    //sort the queue with the new element
    selection_sort(v);
    //increase the size of the queue
    size++;
}

//remove the front element in the queue
template <typename T>
void PQ<T>::pop()
{
    //use for loop to get the first element of the queue
    for (int i = 0; i < v.size(); i++)
    {
        v[i] =  v[i + 1];
    }

    v.pop_back();
    //decrease the size by 1
    size--;
}
