#include "LlistaIOEstudiant.hh"

int Repeticions(const list<Estudiant> & estudiants, int n) {
  list<Estudiant>::const_iterator it;
  int vegades = 0;
  for (it = estudiants.begin(); it != estudiants.end(); ++it) {
    Estudiant a = *it;
    if (a.consultar_DNI() == n) ++vegades;
  }
  return vegades;
}

int main() {
  list<Estudiant> estudiants;
  int n;
  LlegirLlistaEstudiant(estudiants);
  cin >> n;
  int vegades = Repeticions(estudiants, n);
  cout << n << " " << vegades << endl;
}
