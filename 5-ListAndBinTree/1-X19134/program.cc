#include "LlistaIOParInt.hh"

void Calcular(const list<ParInt>& l, int& p, int& suma, int n) {
  p = 0;
  suma = 0;
  list<ParInt>::const_iterator it = l.begin();
  for (int i = 0; i < l.size(); ++i) {
    ParInt a = *it;
    if (a.primer() == n) {
      ++p;
      suma += a.segon();
    }
    ++it;
  }
}

int main() {
  list<ParInt> l;
  int n, p, suma;
  LlegirLlistaParInt(l);
  cin >> n;
  Calcular(l, p, suma, n);
  cout << n << " " << p << " " << suma << endl;
}
