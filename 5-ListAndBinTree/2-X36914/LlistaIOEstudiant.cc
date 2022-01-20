#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l) {
  Estudiant a;
  a.llegir();
  while (a.consultar_DNI() != 0 or a.consultar_nota() != 0) {
    l.insert(l.end(), a);
    a.llegir();
  }
}

void EscriureLlistaEstudiant(const list<Estudiant>& l) {
  list<Estudiant>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it) {
    Estudiant a = *it;
    a.escriure();
  }
}
