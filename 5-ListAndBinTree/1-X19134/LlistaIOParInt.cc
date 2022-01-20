#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l) {
  ParInt a;
  bool b = a.llegir();
  while (b) {
    l.insert(l.end(), a);
    b = a.llegir();
  }
}

void EscriureLlistaParInt(const list<ParInt>& l) {
  list<ParInt>::const_iterator it;
  for (it = l.begin(); it != l.end(); ++it) {
    ParInt a = *it;
    a.escriure();
  }
}
