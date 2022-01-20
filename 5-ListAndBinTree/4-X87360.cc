//#include <iostream>
#include <list>
using namespace std;

void inter(list<int>& uno, const list<int>& dos)
/* Pre: uno = U */
 /* Post: uno pasa a ser la interseccion de U y dos */
 {
    list<int>::iterator it1 = uno.begin();
    list<int>::const_iterator it2 = dos.begin();
    while (it2 != dos.end() and it1 != uno.end()) {
      int a = *it1;
      int b = *it2;
      if (a < b) it1 = uno.erase(it1);
      else if (a > b) ++it2;
      else {
        ++it1;
        ++it2;
      }
    }
    while (it1 != uno.end()) {
      it1 = uno.erase(it1);
    }
 }
/*
 int main() {
   list<int> uno;
   list<int> dos;
   int n;
   cin >> n;
   while (n != 0) {
     uno.insert(uno.end(), n);
     cin >> n;
   }
   cin >> n;
   while (n != 0) {
     dos.insert(dos.end(), n);
     cin >> n;
   }
   inter(uno, dos);
   list<int>::iterator it;
   for (it = uno.begin(); it != uno.end(); ++it) {
     int a = *it;
     cout << a << endl;
   }
 }
*/
