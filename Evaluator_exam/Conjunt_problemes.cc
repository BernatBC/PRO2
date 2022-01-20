/** @file Conjunt_problemes.cc
    @brief Implementació de la classe Conjunt_problemes
*/
#include "Conjunt_problemes.hh"

Conjunt_problemes::Conjunt_problemes() {

}

void Conjunt_problemes::afegir_problema(string p) {
  Problema problema;
  problemes[p] = problema;
}

void Conjunt_problemes::afegir_problema(string p, const Problema& problema) {
  problemes[p] = problema;
}

void Conjunt_problemes::eliminar_problema(string p) {
  problemes.erase(p);
}

void Conjunt_problemes::enviament(string p, bool r) {
  problemes.find(p)->second.enviament(r);
}

int Conjunt_problemes::consultar_n_problemes() const {
  return problemes.size();
}

bool Conjunt_problemes::existeix(string p) const {
  map<string,Problema>::const_iterator it = problemes.find(p);
  return it != problemes.end();
}

Problema Conjunt_problemes::consultar_problema(string p) const {
  return problemes.find(p)->second;
}

void Conjunt_problemes::llegir_problemes() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string id;
    cin >> id;
    afegir_problema(id);
  }
}

void Conjunt_problemes::escriure_problemes() const {
  vector<pair<string, Problema>> v_problemes;
  map<string,Problema>::const_iterator it = problemes.begin();
  //Inserir elements a un vector i ordenar-ho
  while (it != problemes.end()) {
    pair<string,Problema> problema;
    problema.first = it->first;
    problema.second = it->second;
    v_problemes.push_back(problema);
    ++it;
  }
  sort(v_problemes.begin(), v_problemes.end(), comp);
  for (int i = 0; i < v_problemes.size(); ++i) {
    cout << v_problemes[i].first;
    v_problemes[i].second.escriure_problema();
  }
}

void Conjunt_problemes::escriure_problemes_enviament() const {
  map<string, Problema>::const_iterator it = problemes.begin();
  while (it != problemes.end()) {
    cout << it->first << endl;
    ++it;
  }
}

void Conjunt_problemes::escriure_problema(string p) const {
  map<string,Problema>::const_iterator it = problemes.find(p);
  cout << it->first;
  it->second.escriure_problema();
}

bool Conjunt_problemes::comp(const pair<string, Problema> &a, const pair<string, Problema> &b) {
  if (a.second.consultar_ratio() == b.second.consultar_ratio()) return a.first < b.first;
  return a.second.consultar_ratio() < b.second.consultar_ratio();
}
