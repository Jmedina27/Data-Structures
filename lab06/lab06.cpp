//Jesus Medina
//July 23, 2019
//lab06.cpp
//lab06

#include "Mtree.h"

int main()
{
    //create a tree of type int 
    Mtree<int> mt;
    //add elements in the tree
    mt.add(3);
    mt.add(5);
    mt.add(7);
    mt.add(13);
    mt.add(1);
    mt.add(20);
    
    //create a variable that holds the size of the tree
    int size = mt.size();
    //print the size of the tree
    cout << "The size of the tree is : " << size << endl;

    //create a user ipnut variable
    int input;
    cout << "Enter a value to see if it is in the tree : ";
    cin >> input;
    cout << endl;

    //if the element was found in the tree print that ut was found
    if (mt.find(input) == true)
    {
        printf("The element %d was found in the tree", input);
    }
}
