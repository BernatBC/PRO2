 #include <iostream>
 #include <list>
 using namespace std;

void Recalcular(const list<int>& l, int& min, int& max) {
  min = 2147483647;
  max = -2147483646;
  list<int>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it) {
    int num = *it;
    if (num > max) max = num;
    if (num < min) min = num;
  }
}

 void Esborrar(list<int>& l, int num, int& n_elements, double& suma) {
   list<int>::iterator it = l.begin();
   bool b = true;
   while (b and it != l.end()) {
     int a = *it;
     if (a == num and b) {
       --n_elements;
       suma -= a;
       it = l.erase(it);
       b = false;
     }
     else {
       ++it;
     }
   }
 }

 int main() {
   int codi, num;
   int n_elements = 0;
   int min = 2147483647;
   int max = -2147483646;
   double suma = 0;
   list<int> l;
   cin >> codi >> num;
   while (codi != 0 or num != 0) {
     if (codi == -1) {
       ++n_elements;
       suma += num;
       if (num > max) max = num;
       if (num < min) min = num;
       l.insert(l.end(), num);
     }
     else if (codi == -2) {
       Esborrar(l, num, n_elements, suma);
       if (num == min or num == max) {
         Recalcular(l, min, max);
       }
     }
     if (l.size() == 0) cout << 0 << endl;
     else cout << min << " " << max << " " << suma/n_elements << endl;
     cin >> codi >> num;
   }
 }
