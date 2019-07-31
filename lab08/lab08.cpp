//Jesus Medina
//July 30, 2019
//Lab 08
//lab08.cpp

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

int hash2(int n)
{
  srand(n);
  return rand();
}

int string2int(string s)
{
  int h = 0;
  int d = 1;
  for (int i = 0; i < s.length(); i++)
  {
    char x = s[i];
    h += (x)*d;
    d = d * 10;
  }
  return h;
}

int main()
{

  string s;
  cout << "enter string:";
  cin >> s;
  cout << endl;
  cout << string2int(s);
  cout << endl;
  cout << hash2(string2int(s)) << endl;

  int r, n;
  cout << "input for r : ";
  cin >> r;
  cout << endl;
  cout << "input for n : ";
  cin >> n;
  cout << endl;

  vector<int> v;
  for (int i = 0; i < r; i++)
  {
    v.push_back(rand() % 100);
  }

  vector<int> a;
  for (int i = 0; i < n; i++)
  {
    a.push_back(-1);
  }

  for (int i = 0; i < v.size(); i++)
  {
    int m = hash2(v[i])%n;

    if (a[m] == -1)
    {
      a[m] = i;
      cout << v[i] << " hashed to " << m << endl;
    }
    else 
    {
      cout << "there is a collision\n";
    }

  }

  int y;
  cout << "Enter a value for y : ";
  cin >> y;
  cout << "\n";

  cout << "The index in vector v is : " << a[hash2(y)%n] << endl;
  cout << "the value in v is : " << v[a[hash2(y)%n]] << endl;
}