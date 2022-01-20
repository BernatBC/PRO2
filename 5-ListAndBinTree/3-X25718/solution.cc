#include "solution.hh"

void esborra_tots(list<Estudiant> &t, int x) {
  list<Estudiant>::iterator it = t.begin();
  while (it != t.end()) {
    Estudiant a = *it;
    if (a.consultar_DNI() == x) it = t.erase(it);
    else ++it;
  }
}
