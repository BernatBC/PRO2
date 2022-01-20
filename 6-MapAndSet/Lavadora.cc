#include "Lavadora.hh"

//Constructoras
Lavadora::Lavadora() {
  col = false;
  pes = 0;
  ini = false;
  pesmax = 0;
}

//Modificadoras
void Lavadora::inicializar(int pmax, bool col) {
  pesmax = pmax;
  this->col = col;
  ini = true;
  pes = 0;
  list<Prenda> a;
  prendas = a;
}

void Lavadora::anadir_prenda (const Prenda& p) {
  prendas.insert(prendas.end(), p);
  pes += p.consul_peso();
}

void Lavadora::lavado () {
  ini = false;
}

// Consultoras
bool Lavadora::esta_inicializada() const {
  return ini;
}

bool Lavadora::consultar_color() const {
  return col;
}

int Lavadora::consultar_peso() const {
  return pes;
}

int Lavadora::consultar_peso_maximo() const{
  return pesmax;
}

// Escritura de la lavadora
void Lavadora::escribir() const {
  cout << "Lavadora";
  if (col) cout << " de color";
  else cout << " blanca";
  cout << ", con peso actual " << pes << " y peso maximo " << pesmax << "; sus prendas son" << endl;
  list<Prenda>::const_iterator it = prendas.begin();
  while (it != prendas.end()) {
    Prenda aux = *it;
    aux.escribir();
    ++it;
  }
  cout << endl;
}
