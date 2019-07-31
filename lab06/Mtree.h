//Jesus Medina
//July 25, 2019
//Mtree.h

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Tnode
{
public:
    T data;
    Tnode *lptr; //left ptr
    Tnode *rptr; //right ptr
};

template <typename T>
class Mtree
{
public:
    Mtree();       //constructor
    void add(T x); //adds an element to tree
    void del(T x);
    bool find(T x);              //finds an elenent in the tree
    int size() { return tsize; } //returns the size of the tree
    vector<T> inorder()
    {
        v.clear();
        inorder(root);
        return v;
    }

private:
    Tnode<T> *root;
    int tsize;
    void add(Tnode<T> *ptr, T x);
    void del(Tnode<T> *ptr, T x);
    bool find(Tnode<T> *ptr, T x);
    vector<T> v;
    void inorder(Tnode<T> *ptr);
    void preorder(Tnode<T> *ptr);
    void postorder(Tnode<T> *ptr);
};

//default constructor
//set tree and the root of the tree to zero
template <typename T>
Mtree<T>::Mtree()
{
    tsize = 0;
    root = 0;
}

template <typename T>
void Mtree<T>::inorder(Tnode<T> *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        inorder(ptr->lptr);
        v.push_back(ptr->data);
        inorder(ptr->rptr);
    }
    
}

template <typename T>
void Mtree<T>::preorder(Tnode<T> *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        v.push_back(ptr->data);
        preorder(ptr->lptr);
        preorder(ptr->rptr);
    }
}

template <typename T>
void Mtree<T>::postorder(Tnode<T> *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        postorder(ptr->lptr);
        postorder(ptr->rptr);
        delete ptr;
    }
}

//function that adds an element to the tree
template <typename T>
void Mtree<T>::add(T x)
{
    //if the tree is empty
    //then create a ptr and set its lptr and rptr to NULL
    //set the root's data to x
    //increment the size and return
    if (tsize == 0)
    {
        Tnode<T> *ptr = new Tnode<T>;
        ptr->data = x;
        ptr->lptr = 0;
        ptr->rptr = 0;
        root = ptr;
        tsize++;
        return;
    }
    //else if the tree is not empty
    //then call back the add function
    else
    {
        add(root, x);
    }
}

//recursive add function
template <typename T>
void Mtree<T>::add(Tnode<T> *ptr, T x)
{
    //if element is is less than or equal to the ptr-> data
    //and the ptr->lptr is equal to NULL
    if (x <= ptr->data and ptr->lptr == 0)
    {
        //then create a new ptr and set the data its pointing to equal to x
        Tnode<T> *nptr = new Tnode<T>;
        nptr->data = x;
        //set the nptr -> lptr and rptr equal to NULL
        nptr->lptr = 0;
        nptr->rptr = 0;
        //set the ptr's lptr equal to the new ptr
        ptr->lptr = nptr;
        //increment the size and return
        tsize++;
        return;
    }
    //if the element is greater than or equal to the ptr->data
    //and the ptr->rptr is equal to NULL
    if (x >= ptr->data and ptr->rptr == 0)
    {
        //create a new ptr and set the data its poitning to equal to x
        Tnode<T> *nptr = new Tnode<T>;
        nptr->data = x;
        //set the new ptr's lptr and rptr equal to NULL
        nptr->lptr = 0;
        nptr->rptr = 0;
        //set the ptr-> rptr equal to new ptr
        ptr->rptr = nptr;
        //increment the size and return
        tsize++;
        return;
    }
    //if the element is less than or equal to the data of the ptr
    //and the root lfptr is not empty
    if (x <= ptr->data)
    {
        //then call the function add and have it start off at ptr->lptr
        add(ptr->lptr, x);
    }
    //else if it is greater than or equal to the data of the ptr
    //and the root rptr is not empty
    else
    {
        //then call the function add and have it start off at ptr->rptr
        add(ptr->rptr, x);
    }
}

template <typename T>
void Mtree<T>::del(T x)
{
    if (root->data == x)
    {
        v.clear();
        preorder(root);
        postorder(root);
        for (int i = 0; i < v.size(); i++)
        {
            add(v[i]);
        }
    }
    else
    {
        del(root, x);
    }
}

template <typename T>
void Mtree<T>::del(Tnode<T> *ptr, T x)
{
    if (ptr == 0)
    {
        return;
    }
    if (ptr->lptr->data == x)
    {
        v.clear();
        preorder(ptr->lptr);
        postorder(ptr->lptr);
        ptr->lptr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != x)
            {
                add(v[i]);
            } 
        }
        return;
    }
    if (ptr->rptr->data == x)
    {
       v.clear();
        preorder(ptr->rptr);
        postorder(ptr->rptr);
        ptr->rptr = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != x)
            {
                add(v[i]);
            } 
        }
        return; 
    }
    if (x <= ptr->data)
    {
        del(ptr->lptr, x);
    }
    else 
    {
        del(ptr->rptr, x);
    }
}

//create a function that finds an element in the tree
template <typename T>
bool Mtree<T>::find(T x)
{
    if (tsize == 0)
    {
        return false;
    }
    //return the recursive function find
    return find(root, x);
}

//recursive find function
template <typename T>
bool Mtree<T>::find(Tnode<T> *ptr, T x)
{
    //if the ptr-> data is equal to the element x
    if (ptr->data == x)
    {
        //then return true
        return true;
    }
    //if the ptr is equal to NULL
    if (ptr == 0)
    {
        //return false
        return false;
    }
    //if the element x is less than or equal to the data of the ptr
    if (x <= ptr->data)
    {
        //then return the find function starting at the ptr->lptr
        return find(ptr->lptr, x);
    }
    //else if the element x is greater than or equal to the data of the pointer
    else
    {
        //return the find function but starting off at the ptr->rptr
        return find(ptr->rptr, x);
    }
}
