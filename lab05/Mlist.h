//Jesus Medina
//July 18th, 2019
//Mlist.h

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Lnode
{
public:
    T data;
    Lnode *lptr;
    Lnode *rptr;
};

template <typename T>
class Mlist
{
public:
    typedef Lnode<T> *iterator;
    Mlist()
    {
        first = NULL;
        last = NULL;
        lsize = 0;
    }
    void add(T x);
    void del();
    void del(T x);
    T get_front();
    T get_last();
    T operator[](int i);
    void insert(iterator ix, T x);
    void erase(iterator ix);
    void insert(int i, T x);
    void erase(int i);
    int size() { return lsize; }
    iterator begin() { return first; }
    iterator end() { return last; }

private:
    Lnode<T> *first;
    Lnode<T> *last;
    int lsize;
};

//add element into list
template <typename T>
void Mlist<T>::add(T x)
{
    //create a node ptr
    Lnode<T> *ptr = new Lnode<T>;
    //set the ptr pointing to data equal to the x
    ptr->data = x;
    //if lsize is empty
    if (lsize == 0)
    {
        //set first equal to ptr
        //then set the last equal to ptr
        //then set the ptr point to left and right pointer to NULL
        first = ptr;
        last = ptr;
        ptr->lptr = 0;
        ptr->rptr = 0;
    }
    //else if it has an element in the list
    else
    {
        //set the last->rptr equal to the new value
        //then set the ptr->lptr
        //make sure that ptr-> right is NULL
        //set last equal to ptr
        last->rptr = ptr;
        ptr->lptr = last;
        ptr->rptr = 0;
        last = ptr;
    }
    //increment the size
    lsize++;
}

//delete from the front of the list
template <typename T>
void Mlist<T>::del()
{
    //if list is empty then return
    if (lsize == 0)
    {
        return;
    }
    //if the list only has one element
    if (lsize == 1)
    {
        //delete the value of first
        //set first equal to null
        //set the last equal to null
        //decrement the size and return
        delete first;
        first = 0;
        last = 0;
        lsize--;
        return;
    }
    //else set first equal to first->rptr
    //then delete the first->left which is the old first
    //decrement the size and return
    first->rptr->lptr = 0;
    Lnode<T> *tmp = first->rptr;
    first->rptr = 0;
    first = tmp;
    lsize--;
    return;
}

template <typename T>
void Mlist<T>::del(T x)
{
    if (lsize == 0)
    {
        return;
    }

    if (first->data == x)
    {
        del();
        del(x);
    }

    else
    {
        Lnode<T> *ptr = first;
        Lnode<T> *tmp;
        while (ptr != NULL)
        {
            if (ptr->data == x)
            {
                ptr->lptr->rptr = ptr->rptr;
                ptr->rptr->lptr = ptr->lptr;
                tmp = ptr->rptr;
                ptr->rptr = 0;
                ptr->lptr = 0;
                ptr = tmp;
                lsize--;
            }
            else 
            {
                ptr = ptr->rptr;
            }
        }
    }
    

}
//return the data at front of the list
template <typename T>
T Mlist<T>::get_front()
{
    assert(lsize > 0);
    return first->data;
}

//return the data at last of the list
template <typename T>
T Mlist<T>::get_last()
{
    assert(lsize > 0);
    return last->data;
}
//create operator []
template <typename T>
T Mlist<T>::operator[](int i)
{
    //make sure that the index is equal greater than or equal to 0
    //and index is less than the list size
    assert(i >= 0 and i < lsize);
    //create a lnode ptr
    Lnode<T> *ptr = first;
    //go through the list until ptr is less than the given index
    for (int j = 0; j != i; j++)
    {
        ptr = ptr->rptr;
    }
    //return the ptr pointing to data
    return ptr->data;
}

//insert a value at the index using iterators
template <typename T>
void Mlist<T>::insert(iterator ix, T x)
{
    //create a new lnode ptr
    Lnode<T> *ptr = new Lnode<T>;
    //set the ptr -> data equal to x
    ptr->data = x;
    //if the iterator is equal to 0
    //then call add function and return
    if (ix == 0)
    {
        this->add(x);
        return;
    }
    //if the iterator is equal to the front of the list
    if (ix == first)
    {
        //then set the pointer pointing to the rptr equal to first
        //then set the the ptr->lptr equal to null
        //set first equal to ptr
        //increment the size and return
        ptr->rptr = first;
        ptr->lptr = 0;
        first = ptr;
        lsize++;
        return;
    }
    //else if the iterator is equal to anywhere else between
    //set the ptr -> lptr equal to the iterator pointing to lptr
    //set the ptr->rptr equal to the iterator
    //set the iterator's old left pointer to pointing to the right equal to ptr
    //set the iterator's left point equal to ptr
    //increment the size and return
    ptr->lptr = ix->lptr;
    ptr->rptr = ix;
    ix->lptr->rptr = ptr;
    ix->lptr = ptr;
    lsize++;
    return;
}

//function to erase value using an iterator ix
template <typename T>
void Mlist<T>::erase(iterator ix)
{
    //check that the iterator is not equal to null
    //and the size of the list is greater than 0
    assert(ix != NULL and lsize > 0);
    //if the iterator is equal to first
    if (ix == first)
    {
        //then set the iteraotr rptr pointing to the left is equal to null
        //set first equal to the iterator pointing to the right
        //delete the iterator
        //decrement the size and return
        ix->rptr->lptr = 0;
        first = ix->rptr;
        delete ix;
        lsize--;
        return;
    }
    //if the iteratro is equal to last
    if (ix == last)
    {
        //then set the iterator lptr pointing to the right equal to null
        //set last ewual to the iterator's old lptr
        //delete the iterator
        //decrement the size and return
        ix->lptr->rptr = 0;
        last = ix->lptr;
        delete ix;
        lsize--;
        return;
    }
    //else set iterator lptr pointing to the rptr equal to the iterator's rptr
    //set the iterator rptr pointing to the lptr equal to the iterator's lptr
    //decrement the size and return
    ix->lptr->rptr = ix->rptr;
    ix->rptr->lptr = ix->lptr;
    lsize--;
    return;
}

//function to insert value x at the index
template <typename T>
void Mlist<T>::insert(int i, T x)
{
    //check that the index is greater or equal to 0
    //check i is less than the size of the list
    assert(i >= 0 and i < lsize);
    //create an iterator and set it equal to first
    iterator ix = begin();
    //use for loop to go through the list
    //until the iterator is less than the given index
    for (int j = 0; j < i; j++)
    {
        ix = ix->rptr;
    }
    //call the insert function that uses iterators
    insert(ix, x);
}

//function to erase the value at the given index
template <typename T>
void Mlist<T>::erase(int i)
{
    //create an iterator ix and set it equal to first
    iterator ix = begin();
    //use for loop to go through the list
    //until the iterator is less than the given index
    for (int j = 0; j < i; j++)
    {
        ix = ix->rptr;
    }
    //call the erase function that uses iterators
    erase(ix);
}