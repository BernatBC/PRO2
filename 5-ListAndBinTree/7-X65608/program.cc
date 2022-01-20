#include "BinTreeIOEst.hh"

void Nivell(const BinTree<Estudiant>& arbre, int& num, int& nota, int& profunditat, int& trobat) {
  if (not arbre.empty()) {
    Estudiant a = arbre.value();
    if (a.consultar_DNI() == num) {
      if (trobat == -1 or trobat > profunditat) {
        if (a.te_nota()) nota = a.consultar_nota();
        else nota = -1;
        trobat = profunditat;
      }
    }
    else {
      ++profunditat;
      Nivell(arbre.left(), num, nota, profunditat, trobat);
      Nivell(arbre.right(), num, nota, profunditat, trobat);
      --profunditat;
    }
  }
}

int main() {
  BinTree<Estudiant> arbre;
  read_bintree_est(arbre);
  int num;
  while (cin >> num) {
    int nota = -1;
    int profunditat = 0;
    int trobat = -1;
    Nivell(arbre, num, nota, profunditat, trobat);
    if (trobat != -1) cout << num << " " << trobat << " " << nota << endl;
    else cout << num << " " << -1 << endl;
  }
}
