#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

//written by dj910401

int main(void)
{
   unsigned long long num1, num2;
   string n1, n2, n3, n4;
   string result1, result2;
   string sum;

   cin >> n1 >> n2 >> n3 >> n4;
   result1 = n1 + n2;
   result2 = n3 + n4;
   num1 = stold(result1);
   num2 = stold(result2);
   
   cout << num1+num2;
}
