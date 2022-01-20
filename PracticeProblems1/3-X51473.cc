#include <iostream>
#include <list>
using namespace std;

void seleccio(const list<double>& l, list<double>& sel) {
  int element = 1;
  list<double>::const_iterator it = l.begin();
  double suma = *it;
  sel.insert(sel.end(), *it);
  ++it;
  while (it != l.end()) {
    if (*it >= suma/element) sel.insert(sel.end(), *it);
    ++element;
    suma += *it;
    ++it;
  }
}
/*
int main() {
  int n;
  cin >> n;
  list<double> l;
  for (int i = 0; i < n; ++i) {
    double num;
    cin >> num;
    l.insert(l.end(), num);
  }
  list<double> sel;
  seleccio(l, sel);

  list<double>::const_iterator it = sel.begin();
  while (it != sel.end()) {
    cout << ' ' <<  *it;
    ++it;
  }
  cout << endl;
}
*/
