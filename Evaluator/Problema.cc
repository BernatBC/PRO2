/** @file Problema.cc
    @brief Implementació de la classe Problema
*/
#include "Problema.hh"

Problema::Problema() {
  totals = 0;
  correctes = 0;
}

void Problema::enviament(bool correcte) {
  ++totals;
  if (correcte) ++correctes;
}

int Problema::consultar_enviaments_totals() const {
  return totals;
}

double Problema::consultar_ratio() const {
  return (double)(totals + 1)/(correctes + 1);
}

void Problema::escriure_problema() const {
  cout << "(" << totals << "," << correctes << "," << consultar_ratio() << ")" << endl;
}

void Problema::escriure_problema_enviament() const {
  cout << "(" << totals << ")" << endl;
}
