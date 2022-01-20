/** @file Colleccio_cursos.cc
    @brief Implementació de la classe Colleccio_cursos
*/
#include "Colleccio_cursos.hh"

Colleccio_cursos::Colleccio_cursos() {
}

void Colleccio_cursos::afegir_curs(const Curs& c) {
  cursos.push_back(c);
}

void Colleccio_cursos::afegir_inscrit(int c) {
  cursos[c - 1].afegir_inscrit();
}

void Colleccio_cursos::eliminar_inscrit(int c) {
  cursos[c - 1].eliminar_inscrit();
}

void Colleccio_cursos::afegir_completat(int c) {
  cursos[c - 1].afegir_completat();
}

int Colleccio_cursos::consultar_n_inscrits(int c) const {
  return cursos[c - 1].consultar_n_inscrits();
}

int Colleccio_cursos::consultar_n_cursos() const {
  return cursos.size();
}

bool Colleccio_cursos::existeix(int c) const {
  return c <= cursos.size() and c > 0;
}

string Colleccio_cursos::consultar_sessio(int c, string p) const {
  return cursos[c - 1].consultar_sessio(p);
}

Curs Colleccio_cursos::consultar_curs(int c) const {
  return cursos[c - 1];
}

void Colleccio_cursos::llegir_cursos(const Conjunt_sessions& sessions) {
  int n;
  cin >> n;
  cursos = vector<Curs>(n);
  for (int i = 0; i < n; ++i) {
    Curs curs;
    curs.llegir_curs(sessions);
    cursos[i] = curs;
  }
}

void Colleccio_cursos::escriure_cursos() const {
  for (int i = 0; i < cursos.size(); ++i) {
    cout << i + 1;
    cursos[i].escriure_curs();
  }
}

void Colleccio_cursos::escriure_curs(int c) const {
  cout << c;
  cursos[c - 1].escriure_curs();
}
