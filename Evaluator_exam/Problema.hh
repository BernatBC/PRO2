/** @file Problema.hh
    @brief Especificació de la classe Problema
*/
#ifndef PROBLEMA_HH
#define PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif

using namespace std;

/** @class Problema
    @brief Representa el conjunt de característiques i operacions de problemes.
*/

class Problema {
private:
  /** @brief Nombre d'enviaments totals*/
  int totals;
  /** @brief Nombre d'enviaments correctes*/
  int correctes;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea un problema buit
  */
  Problema();

  //Modificadores

  /** @brief Modificadora del nombre d'enviaments totals i correctes
      \pre Cert
      \post Afageix un enviament correcte si el boleà és cert, incorrecte altrament
  */
  void enviament(bool correcte);

  //Consultores

  /** @brief Consultora del nombre d'enviaments totals
      \pre Cert
      \post El resultat és el nombre d'enviaments totals
  */
  int consultar_enviaments_totals() const;

  /** @brief Consultora de la ratio d'enviaments
      \pre Cert
      \post El resultat és (enviaments_totals + 1)/(enviaments_corrrectes + 1)
  */
  double consultar_ratio() const;

  //Lectura i escriptura

  /** @brief Operació d'escriptura d'un problema
      \pre Cert
      \post Es mostra pel canal de sortida estandard el nombre d'enviaments totals i correctes, i la ràtio (enviaments totals + 1)/(enviaments corrrectes + 1)
  */
  void escriure_problema() const;

  /** @brief Operació d'escriptura d'un problema
      \pre Cert
      \post Es mostra pel canal de sortida estandard el nombre d'enviaments totals
  */
  void escriure_problema_enviament() const;
};

#endif
