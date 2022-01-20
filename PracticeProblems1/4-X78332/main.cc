#include <iostream>
#include <stack>
#include "BinTree.hh"
using namespace std;

int elements(const BinTree<int>& a, stack<int>& c) {
  if (a.empty()) {
    return 0;
  }
  else {
    stack<int> c1, c2;
    int e1 = elements(a.left(), c1);
    int e2 = elements(a.right(), c2);
    if (e1 >= e2) c = c1;
    else c = c2;
    c.push(a.value());
    return e1 + e2 + 1;
  }
}

void cami_preferent(const BinTree<int>& a, stack<int>& c) {
  elements(a, c);
}
/*
void BinTreeIn(BinTree<int>& a) {
  int num;
  cin >> num;
  if (num != 0) {
    BinTree<int> l;
    BinTree<int> r;
    BinTreeIn(l);
    BinTreeIn(r);
    a = BinTree<int>(num, l, r);
  }
}

int main() {
  BinTree<int> a;
  BinTreeIn(a);
  stack<int> c;
  cami_preferent(a, c);

  while (not c.empty()) {
    cout << " " << c.top();
    c.pop();
  }
  cout << endl;
}*/
