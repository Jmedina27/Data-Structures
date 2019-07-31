//Jesus Medina
//005172852
//Lab 1 Part 2
//lab1p2.cpp

#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    //create two vectors of type characters
    vector<char> x;
    vector<char> y;

    //create a stack
    Stack<char> stack = Stack<char>();

    //create a variable of type char
    char c;
    c = cin.get();

    while (c != ';')
    {
        x.push_back(c);
        c = cin.get();
    }

    x.push_back(']');
    stack.push('[');

    for (int i = 0; i < x.size(); i++)
    {
        //if the value is a open paranthessis or open bracket, then push the value into the stack
        if (x[i] == '(' || x[i] == '[')
        {
            stack.push(x[i]);
            cout << "Opening parenthesis and bracket added to stack\n";
        }
        //else if the value is a closed paranthesis or closed bracket
        else if (x[i] == ')' || x[i] == ']')
        {
            cout << "test" << endl;
            //while the top of the stack is not equal to the open parenrhesis or open bracket
            //push the top of the stack to the output y and pop the stack
            while (stack.gettop() != '(' || stack.gettop() != '[')
            {
                y.push_back(stack.gettop());
                stack.pop();
            }
            cout << "closing parenthesis popped from stack" << endl;
            //pop the stack
            stack.pop();
        }
        //else if the  value is a multiplication or division operator
        else if (x[i] == '*' || x[i] == '/')
        {
            //while the top of the stack is equal to the mulitplication or division operator
            //then push the value of the top of the stack to the output y and pop the stack
            while (stack.gettop() == '*' or stack.gettop() == '/')
            {
                y.push_back(stack.gettop());
                stack.pop();
            }
            //push the value into the stack
            stack.push(x[i]);
            cout << "operator '*' or '/' added\n";
        }
        //else if the value is a addition or subtraction operator
        else if (x[i] == '+' || x[i] == '-')
        {
            //while the top of the stack is equal to the operators
            //then push the value of the top of the stack to the output y, and then pop the stack
            while (stack.gettop() == '*' or stack.gettop() == '/' or stack.gettop() == '+' or stack.gettop() == '-')
            {
                y.push_back(stack.gettop());
                stack.pop();
            }
            //push the value to the stack
            stack.push(x[i]);
            cout << "operator '+' or '-' added to stack\n";
        }
        //else if the value is an operand, then push it to the output y
        else
        {
            y.push_back(x[i]);
            cout << "operand added\n";
        }

        x.erase(x.begin());
    }
    for (int i = 0; i < y.size(); i++)
    {
        cout << y[i];
    }
}
