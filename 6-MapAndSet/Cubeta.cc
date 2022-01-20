#include "Cubeta.hh"

//Constructoras
Cubeta::Cubeta() {

}

Cubeta::Cubeta(const Cubeta& c) {
  ropacolor = c.ropacolor;
  ropablanca = c.ropablanca;
}


//Modificadoras
void Cubeta::anadir_prenda(const Prenda& p) {
  if (p.consul_color()) ropacolor.push(p);
  else ropablanca.push(p);
}

void Cubeta::completar_lavadora(Lavadora& lav) {
  if (lav.consultar_color()) completar_lavadora_pila_it(ropacolor, lav);
  else completar_lavadora_pila_it(ropablanca, lav);
}

// Escritura de una cubeta
void Cubeta::escribir() const {
  cout << "Ropa de color de la cubeta: " << endl;
  escribir_pila_prenda(ropacolor);
  cout << "Ropa blanca de la cubeta: " << endl;
  escribir_pila_prenda(ropablanca);
}

//Altres
void Cubeta::completar_lavadora_pila_it(stack<Prenda>& p, Lavadora& l) {
  bool completar = true;
  Prenda aux;
  if (p.empty()) completar = false;
  else aux = p.top();
  while (completar) {
    if (l.consultar_peso_maximo() >= l.consultar_peso() + aux.consul_peso()) {
      l.anadir_prenda(aux);
      p.pop();
      if (p.empty()) completar = false;
      else aux = p.top();
    }
    else completar = false;
  }
}

void Cubeta::escribir_pila_prenda(const stack<Prenda>& p) {
  stack<Prenda> aux = p;
  while (not aux.empty()) {
    Prenda roba = aux.top();
    roba.escribir();
    aux.pop();
  }
}
