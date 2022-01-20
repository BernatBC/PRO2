#include "BinTreeIOParInt.hh"

void Nivell(const BinTree<ParInt>& arbre, int& num, int& company, int& profunditat, int& trobat) {
  if (trobat == -1 and not arbre.empty()) {
    ParInt a = arbre.value();
    if (a.primer() == num) {
      company = a.segon();
      trobat = profunditat;
    }
    else {
      ++profunditat;
      Nivell(arbre.left(), num, company, profunditat, trobat);
      Nivell(arbre.right(), num, company, profunditat, trobat);
      --profunditat;
    }
  }
}

int main() {
  BinTree<ParInt> arbre;
  read_bintree_parint(arbre);
  int num;
  while (cin >> num) {
    int company, profunditat = 0;
    int trobat = -1;
    Nivell(arbre, num, company, profunditat, trobat);
    if (trobat != -1) cout << num << " " << company << " " << trobat << endl;
    else cout << -1 << endl;
  }
}
