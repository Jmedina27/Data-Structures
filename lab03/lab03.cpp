// Jesus Medina 
// 005172852
//July 9th, 2019
//lab03.cpp

#include "PQ.h"
#include <random>

int main()
{
    // create a variable of type int to declare the size of the queue
    int r = 0, n = 0;
    cout << "Enter r: ";
    cin >> r;

    //create a vector v 
    vector<int> v;

    srand(time(NULL));
    //push random integers into the vector v
    for (int i = 0; i < r; i++)
        v.push_back(rand());

    //create a queue with all the elements in vector v
    PQ<int> pq1 = PQ<int>(v);

    //create another queue with no values
    PQ<int> pq2 = PQ<int>();
    //add the 7 elements into the queue 
    pq2.push(3);
    pq2.push(4);
    pq2.push(2);
    pq2.push(10);
    pq2.push(5);
    pq2.push(7);
    pq2.push(8);
    
    //print both queue
    cout << "The elements in the 1st Queue are : ";
    pq1.print();
    cout << "The elements in the 2nd Queue are: ";
    pq2.print();

    //create a variable that holds the value of the size of the queue
    int size1 = pq1.get_size();
    int size2 = pq2.get_size();
    //output the size of the queue
    cout << "The size of the First Queue is : " << size1 << endl;
    cout << "The size of the Second Queue is : " << size2 << endl;


    //create a variable that holds the value of the top element of the queue
    int front1 = pq1.get_front();
    int front2 = pq2.get_front();
    //output the top element
    cout << "The element at the front  of the 1st Queue is : " << front1 << endl;
    cout << "The element at the front  of the 2nd Queue is : " << front2 << endl;

    
    //remove an element from the queue
    pq1.pop();
    pq2.pop();
    pq2.pop();


    //print the modified queue
    cout << "The elements in the updated 1st Queue are : ";
    pq1.print(); 
    cout << "The elements in the updated 2nd Queue are : ";
    pq2.print();


}
