//Jesus Medina
//lab05.cpp

#include "Mvector.h"
#include <random>
int main()
{
    int n;
    cout << "enter the size for a vector\n";
    cin >> n;

    //create two vector
    //first vector is create default with a size of 0 and capacity of 10
    Mvector<int> v1 = Mvector<int>();
    //second vector 
    Mvector<int> v2 = Mvector<int>(n);

    //push in random values into the vector 
    srand(time(NULL));
    for (int j = 0; j < n; j++)
    {
        v2.push_back(rand());
    }

    //push some elements into the vector 
    v1.push_back(12);
    v1.push_back(19);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(25);
    v1.push_back(1);

    //use the print function to print the elemnents in the vector
    cout << "The elements in vector 1 are : ";
    v1.print();

    cout << "The elements in vector 2 are : ";
    v2.print();

    //create two varaible that contains the size of the vectors
    int size1 = v1.size();
    int size2 = v2.size();

    cout << "The size of vector 1 is : " << size1 << endl;
    cout << "The size of vector 2 is : " << size2 << endl;

    //erase data from the back of the vector and erase data at a certain index
    v1.pop_back();
    v1.erase(3);
    //push new values into the vector
    v1.insert(4, 3);
    v1.push_back(4);
    v1.push_back(17);
    v1.push_back(23);
    v1.push_back(27);
    v1.push_back(30);
    v1.push_back(50);

    //use the print fucntion to print out all the elements in the vector
    cout << "The elements in the updated vector 1 are :";
    v1.print();
    //get the size of the newly created vector 
    size1 = v1.size();
    cout << "The size of the updated vector 1 is : " << size1 << endl;

    //ensure that the capacity doubles when size is less than capacity
    int cap1 = v1.capacity();
    cout << "The capacity of the first vector is : " << cap1 << endl;

    //clear the vector 
    v1.clear();

    //get the new size of the vector
    size1 = v1.size();
    cout << "The size of the first vector is : " << size1 << endl;

    //push in new values to the empty vector
    v1.push_back(11);
    v1.push_back(15);

    //erase the value at index 1
    v1.erase(1);

    //print the result of the erase 
    v1.print();

}