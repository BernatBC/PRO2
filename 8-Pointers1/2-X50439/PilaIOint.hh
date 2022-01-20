#ifndef PILA_IO_INT
#define PILA_IO_INT

#include "utils.PRO2"
#include "Pila.hh"

void llegir_pila_int(Pila<int> &p, int marca)
{
  int n;
  cin >> n;
  while (n != marca){
    p.empilar(n);
    cin >> n;
  }
}

void escriure_pila_int(const Pila<int> &p)
{
  cout << "[Cim] " << endl;
  Pila<int> copia(p); // copiamos p para que no se destruya y no tener 
  while(not copia.es_buida()){ //que acordarnos de copiarla fuera
    cout << copia.cim() << endl;
    copia.desempilar(); // el que no haya salto de linea solo interesa
  }                   // si la pila no es muy grande
  cout << "[Ultim]"<<endl;
}

#endif
