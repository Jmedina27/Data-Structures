//Jesus Medina 
//Mvector.h

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Mvector
{
public:
    Mvector();  
    Mvector(unsigned int n);
    void push_back(T x);
    void pop_back();
    void clear();
    void insert(int i, T x);
    void erase(int i);
    void print();
    T operator[](unsigned int i);
    int size();
    int capacity();

private:
    int vsize;
    int vcap;
    T *v;
    void reserve(unsigned int n);
};

//default constructor
template <typename T>
Mvector<T>::Mvector()
{
    //create a pointer newv
    T *newv = new T[10];
    //check that the pointer is not pointing to null
    assert(newv != NULL);
    //set the size to 0 and the capacity of the vector to 10
    vsize = 0;
    vcap = 10;
    v = newv;
}

template <typename T>
Mvector<T>::Mvector(unsigned int n)
{
    T *newv = new T[n];
    assert(newv != NULL);
    vsize = 0;
    vcap = n;
    v = newv;
}

template <typename T>
void Mvector<T>::reserve(unsigned int n)
{
    //check that the size is greater than the capacity
    assert(n > vcap);
    T *newv = new T[n];
    for (int i = 0; i < vsize; i++)
    {
        newv[i] = v[i];
    }

    delete[] v;
    v = newv;
    vcap = n;
}

//add items to the vector
template <typename T>
void Mvector<T>::push_back(T x)
{
    //if the size of the vector is less than the vector's capacity 
    if (vsize < vcap)
    {
        //add the element to the end of the vector and increment the size
        v[vsize] = x;
        vsize++;
    }
    //else if the vector is equal to the capacity 
    else
    {
        //call the function reserve to create a new vector and double the capacity
        reserve(2 * vcap);
        //add the element to the end of the vector and increment the size
        v[vsize] = x;
        vsize++;
    }
}

//remove an element from the back of the vector 
template <typename T>
void Mvector<T>::pop_back()
{
    //check that the size of the vector is not greater than 0
    assert(vsize > 0);
    //decrement the size;
    vsize--;
}

//clear the vector
template <typename T>
void Mvector<T>::clear()
{
    //set the size equal to zero
    vsize = 0;
}

//insert an element at a specific index
template <typename T>
void Mvector<T>::insert(int i, T x)
{
    //check that the index is greater than or equal to 0
    //and less than or equal to the size of the vector
    assert(i >= 0 and i <= vsize);
    //if the capacity of the vector is equal to the size of the vector
    if (vcap == vsize)
    {
        //call the function reserve
        reserve(2 * vcap);
    }
    //go through the vector from the end of the vector
    //and keep going until j is greater than the index
    for (int j = vsize; j > i; j--)
    {
        v[j] = v[j - 1];
    }
    //set the index where the for loop stopped equal to the value x
    v[i] = x;
    //increment the size
    vsize++;
}

//erase an element in the vector at index i 
template <typename T>
void Mvector<T>::erase(int i)
{
    //check that index is greater than or equal to 0 
    //and that it is less than size 
    assert(i >= 0 and i < vsize);
    //
    for (int j = i; j < vsize - 1; j++)
    {
        v[j] = v[j + 1];
    }
    vsize--;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{
    assert(i >= 0 and i < vsize);
    return v[i];
}

//return the size of the vector
template <typename T>
int Mvector<T>::size()
{
    return vsize;
}

//return the capacity of the vector
template <typename T>
int Mvector<T>::capacity()
{
    return vcap;
}

//print all the elements in the vector 
template <typename T>
void Mvector<T>::print()
{
    for (int i = 0; i < vsize; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
