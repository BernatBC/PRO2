/** @file Curs.hh
    @brief Especificació de la classe Curs
*/
#ifndef CURS_HH
#define CURS_HH

#include "Conjunt_problemes.hh"
#include "Conjunt_sessions.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#include <map>
#endif

/** @class Curs
    @brief Representa el conjunt de característiques i operacions de cursos.

    Fem ús d'un vector per representar les diferentes sessions i una altra estructura de dades per ser més eficients de temps en operacions com consultar_sessio
*/

class Curs {
private:
  /**@brief Comptador de nombre d'inscrits*/
  int n_inscrits;
  /**@brief Comptador de vegades que s'ha completat el curs*/
  int n_completats;
  /**@brief Vector que conté les sessions del curs*/
  vector<string> sessions;
  /**@brief Map que conté com a clau cada l'identificador de cada problema del curs, i com a valor l'identificador de la sessió on pertany*/
  map<string, string> sessions_problemes;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea un curs buit
  */
  Curs();

  //Modificadores

  /** @brief Modificadora del nombre de vegades completat
      \pre Cert
      \post Incrementa el nombre de vegades completat en una unitat
  */
  void afegir_completat();

  /** @brief Modificadora del nombre d'usuaris inscrits
      \pre Cert
      \post Incrementa el nombre d'usuaris inscrits en una unitat
  */
  void afegir_inscrit();

  /** @brief Modificadora del nombre d'usuaris inscrits
      \pre Cert
      \post Decrementa el nombre d'usuaris inscrits en una unitat
  */
  void eliminar_inscrit();

  //Consultores

  /** @brief Consultora del nombre d'usuaris inscrits al curs
      \pre Cert
      \post El resultat és el nombre d'usuaris que estan inscrits en el curs
  */
  int consultar_n_inscrits() const;

  /** @brief Consultora de repeticions de problemes en un mateix curs
      \pre Cert
      \post El resultat és cert si hi ha alemnys un problema repetit dins el mateix curs
  */
  bool problemes_repetits(const Conjunt_sessions& Conj_sessions) const;

  /** @brief Consultora d'una sessió
      \pre El problema amb identificador p pertany al curs
      \post El resultat és l'identificador de la sessió on pertany el problema amb identificador p
  */
  string consultar_sessio(string p) const;

  /** @brief Consultora de sessions
      \pre Cert
      \post El resultat és un vector amb els identificadors de les sessions del curs
  */
  vector<string> consultar_sessions() const;

  //Lectura i escriptura

  /** @brief Operació de lectura d'un curs
      \pre Entrada vàlida
      \post Es llegeix pel canal d'entrada estandard el número de sessions i una seqüència d'identificadors de sessions
  */
  void llegir_curs(const Conjunt_sessions& conj_sessions);

  /** @brief Operació de lectura d'un curs
      \pre Entrada vàlida
      \post Es llegeix pel canal d'entrada estandard el número de sessions i una seqüència d'identificadors de sessions. Retorna cert si el curs està ben format, fals altrament
  */
  bool llegir_curs_repetit(const Conjunt_sessions& conj_sessions);

  /** @brief Operació d'escriptura d'un curs
      \pre Cert
      \post Es mostra pel canal de sortida estandard les vegades completat, el nombre d'inscrits, el nombre de sessions i la seqüència d'identificadors de les sessions per ordre que es van llegir
  */
  void escriure_curs() const;

};

#endif
