/** @file Sessio.cc
    @brief Implementació de la classe Sessio
*/
#include "Sessio.hh"

Sessio::Sessio() {
}

Sessio::Sessio(string s) {
  id = s;
}

string Sessio::consultar_id() const {
  return id;
}

int Sessio::consultar_n_problemes() const {
  return map_problemes.size();
}

bool Sessio::problemes_disponibles(const Conjunt_problemes& resolts, Conjunt_problemes& disponibles) const {
  bool completat = true;
  disponibles_bintree(problemes, resolts, disponibles, completat);
  return completat;
}

bool Sessio::actualitzar_disponibles(const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, string p) const {
  bool completat = true;
  disponibles_bintree(map_problemes.find(p)->second, resolts, disponibles, completat);
  return completat;
}

void Sessio::recorre_sessio(map<string,string>& sessions_problemes, string s) const {
  map<string, BinTree<string>>::const_iterator it = map_problemes.begin();
  while (it != map_problemes.end()) {
    sessions_problemes[it->first] = s;
    ++it;
  }
}

void Sessio::llegir_sessio() {
  lectura_bintree(problemes);
}

void Sessio::escriure_sessio() const {
  escriptura_bintree(problemes);
  cout << endl;
}

void Sessio::disponibles_bintree(const BinTree<string>& arbre, const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, bool& completat) const {
  if (not arbre.empty()) {
    if (not disponibles.existeix(arbre.value())) {
      disponibles.afegir_problema(arbre.value());
      completat = false;
      if (resolts.existeix(arbre.value())) {
        disponibles_bintree(arbre.left(), resolts, disponibles, completat);
        disponibles_bintree(arbre.right(), resolts, disponibles, completat);
      }
    }
    else {
      disponibles_bintree(arbre.left(), resolts, disponibles, completat);
      disponibles_bintree(arbre.right(), resolts, disponibles, completat);
    }
  }
}

void Sessio::lectura_bintree(BinTree<string>& arbre) {
  string p;
  cin >> p;
  if (p != "0") {
    BinTree<string> e, d;
    lectura_bintree(e);
    lectura_bintree(d);
    arbre = BinTree<string>(p, e, d);
    map_problemes[p] = arbre;
  }
}

void Sessio::escriptura_bintree(const BinTree<string>& arbre) const {
  if (not arbre.empty()) {
    cout << "(";
    escriptura_bintree(arbre.left());
    escriptura_bintree(arbre.right());
    cout << arbre.value() << ")";
  }
}
