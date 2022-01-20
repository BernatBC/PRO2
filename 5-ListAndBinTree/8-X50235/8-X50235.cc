#include <iostream>
#include "BinTree.hh"
using namespace std;
/*
void read_bintree(BinTree<int>& a) {
  int num;
  cin >> num;
  if (num != 0) {
    BinTree<int> esquerra;
    read_bintree(esquerra);
    BinTree<int> dreta;
    read_bintree(dreta);
    a = BinTree<int> (num, esquerra, dreta);
  }
  else {
    a = BinTree<int> (num);
  }
}

void write_bintree(BinTree<int>& a) {
  int num = a.value();
  cout << num;
  if (num != 0) {
    BinTree<int> esquerra = a.left();
    write_bintree(esquerra);
    BinTree<int> dreta = a.right();
    write_bintree(dreta);
    a = BinTree<int> (num, esquerra, dreta);
  }
  else {
    a = BinTree<int> (num);
  }
}*/

bool poda_subarbre(BinTree<int> &a, int x) {
  bool modificat = false;
  BinTree<int> aux;
  if (not a.empty()) {
    if (a.value() != x) {
      BinTree<int> esquerra = a.left();
      if (poda_subarbre(esquerra, x)) modificat = true;
      BinTree<int> dreta = a.right();
      if (poda_subarbre(dreta, x)) modificat = true;
      aux = BinTree<int> (a.value(), esquerra, dreta);
    }
    else {
      modificat = true;
    }
    a = aux;
    return modificat;
  }
  return false;
}
/*
int main() {
    BinTree<int> a;
    read_bintree(a);
    int n;
    cout << "Num: ";
    cin >> n;
    bool b = poda_subarbre(a, n);
    if (b) {
      cout << "podat" << endl;
    }
    else {
      cout << "no podat" << endl;
    }
    write_bintree(a);
    cout << endl;
}
*/
