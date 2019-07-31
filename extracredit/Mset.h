#include <iostream>
using namespace std;

template <typename T>
class Mset
{
public:
        typedef T *iterator;
        Mset();
        Mset(unsigned int n);
        void pushback(T x);
        void popback();
        void clear();
        void insert(int i, T x);
        void erase(int i);
        T operator[](unsigned int i);
        void operator--(int);
        int size();
        iterator begin() { return v; }
        iterator end() { return v + vsize; }
        void insert(iterator ix, T x);
        void erase(iterator ix);

private:
        int vsize;
        int vcap;
        T *v;
        void reserve(unsigned int n);
        bool duplicate(T x);
};

template <typename T>
Mset<T>::Mset()
{
        v = NULL;
        vsize = 0;
        reserve(10);
}

template <typename T>
Mset<T>::Mset(unsigned int n)
{
        v = NULL;
        vsize = 0;
        reserve(n);
}

template <typename T>
void Mset<T>::pushback(T x)
{
        // check if x exists in the set, if not then insert else discard
        if (!duplicate(x))
        {
                if (vsize == vcap)
                        reserve(vcap * 2);
                v[vsize++] = x;
        }
        else
        {
                cout << "duplicate is found\n";
        }
}

template <typename T>
void Mset<T>::popback()
{
        if (vsize > 0)
        {
                vsize--;
        }
}

template <typename T>
void Mset<T>::clear()
{
        // if v is not null, then delete the existing array
        if (v != NULL)
                delete v;
        v = new T[10]; // allocate a new array of size 10
        vcap = 10;     // set the new capacity
        vsize = 0;
}

template <typename T>
void Mset<T>::insert(int i, T x)
{
        // check if x exists in the set, if not then insert else discard
        if (!duplicate(x))
        {
                if (i >= 0 && i < vsize)
                {
                        if (vsize == vcap)
                                reserve(vcap * 2);
                        for (int j = vsize - 1; j >= i; j--)
                                v[j + 1] = v[j];
                        v[i] = x;
                        vsize++;
                }
        }
        else
        {
                cout << "duplicate is found\n";
        }
}

template <typename T>
void Mset<T>::erase(int i)
{
        if (i >= 0 && i < vsize)
        {
                for (int j = i + 1; j < vsize; j++)
                        v[j - 1] = v[j];
                vsize--;
        }
}

template <typename T>
T Mset<T>::operator[](unsigned int i)
{
        return v[i];
}

template <typename T>
int Mset<T>::size()
{
        return vsize;
}

template <typename T>
void Mset<T>::reserve(unsigned int n)
{
        T *temp = new T[n];
        for (int i = 0; i < vsize; i++)
                temp[i] = v[i];
        if (v != NULL)
                delete[] v;
        v = temp;
        vcap = n;
}

// function to check if x exists in the set or not
template <typename T>
bool Mset<T>::duplicate(T x)
{
        for (int i = 0; i < vsize; i++)
        {
                if (v[i] == x)
                        return true;
        }
        return false;
}