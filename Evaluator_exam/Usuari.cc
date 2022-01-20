/** @file Usuari.cc
    @brief Implementació de la classe Usuari
*/
#include "Usuari.hh"

Usuari::Usuari() {
  enviaments = 0;
  intentats = 0;
  curs = 0;
}

void Usuari::inscriure(int c, Colleccio_cursos& cursos, const Conjunt_sessions& sessions) {
  Curs curs_inscrit = cursos.consultar_curs(c);
  vector<string> v_sessions = curs_inscrit.consultar_sessions();
  curs = c;
  //Actualitzar problemes disponibles
  for (int i = 0; i < v_sessions.size(); ++i) {
      Sessio sessio = sessions.consultar_sessio(v_sessions[i]);
      sessio.problemes_disponibles(resolts, disponibles);
  }
}

void Usuari::enviament(string p, bool resolt, const Conjunt_sessions& sessions, Colleccio_cursos& cursos) {
  ++enviaments;
  disponibles.enviament(p, resolt);
  Problema problema = disponibles.consultar_problema(p);
  if (problema.consultar_enviaments_totals() == 1) ++intentats;
  if (resolt and not resolts.existeix(p)) {
    resolts.afegir_problema(p, problema);
    //Actualitzar problemes enviables
    string s = cursos.consultar_sessio(curs, p);
    if (sessions.actualitzar_disponibles(s, resolts, disponibles, p)) sessions_resoltes.insert(s);
  }
}

void Usuari::desapuntar(Colleccio_cursos& cursos) {
  if (disponibles.consultar_n_problemes() == 0) cursos.afegir_completat(curs);
  cursos.eliminar_inscrit(curs);
  curs = 0;
  Conjunt_problemes aux;
  disponibles = aux;
}

int Usuari::consultar_curs() const {
  return curs;
}

bool Usuari::inscrit() const {
  return curs != 0;
}

bool Usuari::disponible(string p) const {
  return disponibles.existeix(p);
}

void Usuari::escriure_resolts() const {
  resolts.escriure_problemes_enviament();
}

void Usuari::escriure_disponibles() const {
  disponibles.escriure_problemes_enviament();
}

void Usuari::escriure_usuari() const {
  cout << "(" << enviaments << "," << resolts.consultar_n_problemes() << "," << curs << ")" << endl;
}
