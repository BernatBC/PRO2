/** @file Conjunt_usuaris.cc
    @brief Implementació de la classe Conjunt_usuaris
*/
#include "Conjunt_usuaris.hh"

Conjunt_usuaris::Conjunt_usuaris() {

}

void Conjunt_usuaris::afegir_usuari(string u) {
  Usuari usuari;
  usuaris[u] = usuari;
}

void Conjunt_usuaris::eliminar_usuari(string u) {
  usuaris.erase(u);
}

void Conjunt_usuaris::inscriure(string u, int c, Colleccio_cursos& cursos, const Conjunt_sessions& sessions) {
  usuaris.find(u)->second.inscriure(c, cursos, sessions);
}

void Conjunt_usuaris::enviament(string u, string p, int r, const Conjunt_sessions& sessions, Colleccio_cursos& cursos) {
  usuaris.find(u)->second.enviament(p, r, sessions, cursos);
}

void Conjunt_usuaris::desapuntar(string u, Colleccio_cursos& cursos) {
  usuaris.find(u)->second.desapuntar(cursos);
}

int Conjunt_usuaris::consultar_n_usuaris() const {
  return usuaris.size();
}

int Conjunt_usuaris::consultar_curs(string u) const {
  return usuaris.find(u)->second.consultar_curs();
}

bool Conjunt_usuaris::existeix(string u) const {
  return usuaris.find(u) != usuaris.end();
}

bool Conjunt_usuaris::inscrit(string u) const {
  return usuaris.find(u)->second.inscrit();
}

bool Conjunt_usuaris::disponible(string u, string p) const {
  return usuaris.find(u)->second.disponible(p);
}

void Conjunt_usuaris::llegir_usuaris() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string id;
    cin >> id;
    afegir_usuari(id);
  }
}

void Conjunt_usuaris::escriure_problemes_resolts(string u) const {
  usuaris.find(u)->second.escriure_resolts();
}

void Conjunt_usuaris::escriure_problemes_disponibles(string u) const {
  usuaris.find(u)->second.escriure_disponibles();
}

void Conjunt_usuaris::escriure_usuaris() const {
  map<string, Usuari>::const_iterator it = usuaris.begin();
  while (it != usuaris.end()) {
    cout << it->first;
    it->second.escriure_usuari();
    ++it;
  }
}

void Conjunt_usuaris::escriure_usuari(string u) const {
  cout << u;
  usuaris.find(u)->second.escriure_usuari();
}
