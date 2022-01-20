/** @file Curs.cc
    @brief Implementació de la classe Curs
*/
#include "Curs.hh"

Curs::Curs() {
  n_inscrits = 0;
  n_completats = 0;
}

void Curs::afegir_completat() {
  ++n_completats;
}

void Curs::afegir_inscrit() {
  ++n_inscrits;
}

void Curs::eliminar_inscrit() {
  --n_inscrits;
}

int Curs::consultar_n_inscrits() const {
  return n_inscrits;
}

string Curs::consultar_sessio(string p) const {
  map<string, string>::const_iterator it = sessions_problemes.find(p);
  if (it != sessions_problemes.end()) return it->second;
  return "";
}

vector<string> Curs::consultar_sessions() const {
  return sessions;
}

void Curs::llegir_curs(const Conjunt_sessions& conj_sessions) {
  int n;
  cin >> n;
  sessions = vector<string>(n);
  for (int i = 0; i < n; ++i) {
    cin >> sessions[i];
    conj_sessions.recorre_sessio(sessions[i], sessions_problemes);
  }
}

bool Curs::llegir_curs_repetit(const Conjunt_sessions& conj_sessions) {
  int n_sessions;
  int n_problemes = 0;
  cin >> n_sessions;
  //Comprovar que el nombre de problemes de les sessions corresponguin
  sessions = vector<string>(n_sessions);
  for (int i = 0; i < n_sessions; ++i) {
    cin >> sessions[i];
    conj_sessions.recorre_sessio(sessions[i], sessions_problemes);
    n_problemes += conj_sessions.consultar_n_problemes(sessions[i]);
  }
  return sessions_problemes.size() == n_problemes;
}

void Curs::escriure_curs() const {
  cout << " " << n_completats << " " << n_inscrits << " " << sessions.size();
  for (int i = 0; i < sessions.size(); ++i) {
    if (i == 0) cout << " (";
    else cout << " ";
    cout << sessions[i];
  }
  cout << ")" << endl;
}
