/** @file Conjunt_problemes.hh
    @brief Especificació de la classe Conjunt_problemes
*/
#ifndef CONJUNT_PROBLEMES_HH
#define CONJUNT_PROBLEMES_HH

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#endif

using namespace std;

/** @class Conjunt_problemes
    @brief Representa el conjunt de característiques i operacions del conjunt de problemes.
*/
class Conjunt_problemes {
private:
  /**@brief map que conté problemes*/
  map<string,Problema> problemes;

  /** @brief Comparadora de l'ordre de dos problemes
      \pre a i b parella d'identificador i problema vàlids
      \post Retorna cert si la ràtio d'a és menor a la de b, o si és la mateixa, si a té un identificador alfabeticament menor al de b. Reotrna fals altrament.
  */
  static bool comp(const pair<string, Problema> &a, const pair<string, Problema> &b);

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea un conjunt_problemes buit
  */
  Conjunt_problemes();

  //Modificadores

  /** @brief Modificadora de l'addició d'un problema
      \pre El problema amb identificador p no pertany al conjunt
      \post Afageix un problema amb l'identificador p al conjunt
  */
  void afegir_problema(string p);

  /** @brief Modificadora de l'addició d'un problema
      \pre El problema amb identificador p no pertany al conjunt i l'identificador p pertany al problema
      \post Afageix el problema amb l'identificador p al conjunt
  */
  void afegir_problema(string p, const Problema& problema);


  /** @brief Modificadora de l'eliminació d'un problema
      \pre El problema amb identificador p pertany al conjunt
      \post Esborra el problema amb l'identificador p del conjunt
  */
  void eliminar_problema(string p);

  /** @brief Modificadora de l'enviament
      \pre El problema amb identificador p pertany al conjunt
      \post Afageix un enviament correcte en el problema amb identificador p si el boleà és cert, incorrecte altrament
  */
  void enviament(string p, bool r);

  //Consultores

  /** @brief Consultora del nombre de problemes
      \pre Cert
      \post El resultat és el nombre de problemes continguts al conjunt
  */
  int consultar_n_problemes() const;

  /** @brief Consultora de l'existència d'un problema
      \pre Cert
      \post El resultat és cert si el problema amb identificador p està contingut en el conjunt, fals altrament
  */
  bool existeix(string p) const;

  /** @brief Consultora d'un problema'
      \pre El problema amb identificador p pertany al conjunt
      \post El resultat és el problema amb l'identificador p
  */
  Problema consultar_problema(string p) const;

  //Lectura i escriptura

  /** @brief Operació de lectura de problemes
      \pre Cert
      \post Es llegeix pel canal d'entrada el nombre de problemes i una seqüència de problemes que es desen al conjunt
  */
  void llegir_problemes();

  /** @brief Operació d'escriptura de problemes
      \pre Entrada vàlida
      \post Es mostra pel canal de sortida estandard l'identificador, el nombre d'enviaments fets i correctes, i la ràtio (enviaments totals + 1)/(enviaments corrrectes + 1) de cada problema del conjunt ordenats creixentment per la ratio
  */
  void escriure_problemes() const;

  /** @brief Operació d'escriptura de problemes
      \pre Cert
      \post Es mostra pel canal de sortida estandard l'identificador i el nombre d'enviaments totals de cada problema del conjunt ordenats creixentment per la ratio
  */
  void escriure_problemes_enviament() const;

  /** @brief Operació d'escriptura d'un problema
      \pre El problema amb identificador p pertany al conjunt
      \post Es mostra pel canal de sortida estandard l'identificador, el nombre d'enviaments fets i correctes, i la ràtio (enviaments totals + 1)/(enviaments corrrectes + 1) del problema amb identificador p
  */
  void escriure_problema(string p) const ;

};
#endif
