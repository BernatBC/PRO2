/** @file Conjunt_sessions.cc
    @brief Implementació de la classe Conjunt_sessions
*/
#include "Conjunt_sessions.hh"

Conjunt_sessions::Conjunt_sessions() {

}

void Conjunt_sessions::afegir_sessio(const Sessio& s) {
  sessions[s.consultar_id()] = s;
}

int Conjunt_sessions::consultar_n_sessions() const {
  return sessions.size();
}

int Conjunt_sessions::consultar_n_problemes(string s) const {
    return sessions.find(s)->second.consultar_n_problemes();
}

bool Conjunt_sessions::existeix(string s) const {
  return sessions.find(s) != sessions.end();
}

Sessio Conjunt_sessions::consultar_sessio(string s) const {
  return sessions.find(s)->second;
}

bool Conjunt_sessions::actualitzar_disponibles(string s, const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, string p) const {
  return sessions.find(s)->second.actualitzar_disponibles(resolts, disponibles, p);
}

void Conjunt_sessions::recorre_sessio(string s, map<string, string>& sessions_problemes) const {
  sessions.find(s)->second.recorre_sessio(sessions_problemes, s);
}

void Conjunt_sessions::llegir_sessions() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string id;
    cin >> id;
    Sessio sessio = Sessio(id);
    sessio.llegir_sessio();
    afegir_sessio(sessio);
  }
}

void Conjunt_sessions::escriure_sessions() const {
  map<string, Sessio>::const_iterator it = sessions.begin();
  while (it != sessions.end()) {
    cout << it->first << " " << it->second.consultar_n_problemes() << " ";
    it->second.escriure_sessio();
    ++it;
  }
}

void Conjunt_sessions::escriure_sessio(string s) const {
  map<string, Sessio>::const_iterator it = sessions.find(s);
  cout << it->first << " " << it->second.consultar_n_problemes() << " ";
  it->second.escriure_sessio();
}
