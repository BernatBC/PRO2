#include <iostream>
#include <stack>
using namespace std;

 int main() {

   stack<int> pila;

   int n;
   cin >> n;

   int num;

   for (int i = 0; i < (n + 1)/2; ++i) {

     cin >> num;
     pila.push(num);

   }


   bool b = true;

   if (n%2 == 1) {
     pila.pop();
   }

   int i = 0;

   while (b and i < n/2) {

     cin >> num;

     if (num == pila.top()) {
       pila.pop();
     }
     else {
       b = false;
     }

     ++i;
   }

   if (b) {
     cout << "SI" << endl;
   }
   else {
     cout << "NO" << endl;
   }

 }