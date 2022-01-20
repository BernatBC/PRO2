/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.

En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/
int main ()
{
  int opcio;
  Cubeta cubell;
  Lavadora rentadora;
  cin >> opcio;
  while (opcio != -8) {
    //Inicialitzar rentadora
    if (opcio == -1) {
      int pes;
      cin >> pes;
      bool color = readbool();
      if (not rentadora.esta_inicializada() and pes > 0) rentadora.inicializar(pes, color);
    }
    //Afegir peça de roba a la rentadora
    else if (opcio == -2) {
      int pes;
      cin >> pes;
      bool color = readbool();
      Prenda roba(pes, color);
      if (pes > 0 and rentadora.esta_inicializada() and rentadora.consultar_color() == color
      and rentadora.consultar_peso_maximo() <= rentadora.consultar_peso() + pes) rentadora.anadir_prenda(roba);
    }
    //Afegir peça de roba al cubell
    else if (opcio == -3) {
      int pes;
      cin >> pes;
      bool color = readbool();
      Prenda roba(pes, color);
      if (pes > 0) cubell.anadir_prenda(roba);
    }
    //Completar rentadora
    else if (opcio == -4) {
      cubell.completar_lavadora(rentadora);
    }
    //Netejar roba
    else if (opcio == -5) {
      rentadora.lavado();
    }
    //Esriure contingut cubell
    else if (opcio == -6) {
      cout << "   Cubeta: " << endl;
      cubell.escribir();
    }
    //Escriure contingut rentadora
    else if (opcio == -7) {
      cout << "   Lavadora: " << endl;
      if (rentadora.esta_inicializada()) rentadora.escribir();
      else cout << "Lavadora no inicializada" << endl << endl;
    }
    cin >> opcio;
  }
}
