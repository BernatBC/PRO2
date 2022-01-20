/** @file Colleccio_cursos.hh
    @brief Especificació de la classe Colleccio_cursos
*/
#ifndef COLLECCIO_CURSOS_HH
#define COLLECCIO_CURSOS_HH

#include "Curs.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif

/** @class Colleccio_cursos
    @brief Representa el conjunt de característiques i operacions de la col·lecció de cursos.
*/

class Colleccio_cursos {
private:
  /**@brief Vector que conté cursos*/
  vector<Curs> cursos;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea una Colleccio_cursos buit
  */
  Colleccio_cursos();

  //Modificadores

  /** @brief Modificadora de l'addició d'un curs
      \pre Curs c és valid i no conté problemes repetits entre sessions
      \post Afageix el curs c a la col·lecció
  */
  void afegir_curs(const Curs& c);

  /** @brief Modificadora d'inscrits
      \pre Existeix un curs amb l'identificador c
      \post Augmenta en una unitat el nombre d'inscrits en el curs amb identificador c
  */
  void afegir_inscrit(int c);

  /** @brief Modificadora d'inscrits
      \pre Existeix un curs amb l'identificador c
      \post Decreix en una unitat el nombre d'inscrits en el curs amb identificador c
  */
  void eliminar_inscrit(int c);

  /** @brief Modificadora del nombre de vegades completat
      \pre Existeix un curs amb l'identificador c
      \post Augmenta en una unitat el nombre de vegades completat el curs amb identificador c
  */
  void afegir_completat(int c);

  //Consultores

  /** @brief Consultora del nombre d'usuaris inscrits en un curs
      \pre Existeix un curs amb l'identificador c
      \post El resultat és el nombre d'usuaris inscrits en el curs amb identificador c
  */
  int consultar_n_inscrits(int c) const;

  /** @brief Consultora del nombre de cursos
      \pre Cert
      \post El resultat és el nombre de cursos de la col·lecció
  */
  int consultar_n_cursos() const;

  /** @brief Consultora de l'existència d'un curs
      \pre Cert
      \post El resultat és cert si el curs amb identificador c està contingut a la col·lecció, fals altrament
  */
  bool existeix(int c) const;

  /** @brief Consultora de la sessió
      \pre Existeix un curs amb l'identificador c i el problema amb identificador p pertany al curs amb identificador c
      \post El resultat és la sessió en la qual es troba el problema del curs
  */
  string consultar_sessio(int c, string p) const;

  /** @brief Consultora d'un curs
      \pre Existeix un curs amb l'identificador c
      \post El resultat és el curs amb l'identificador c
  */
  Curs consultar_curs(int c) const;

  //Lectura i escriptura

  /** @brief Operació de lectura de cursos
      \pre L'entrada és vàlida i no conté problemes repetitis
      \post Es llegeix pel canal d'entrada estandard el número de sessions i una seqüència d'identificadors de sessions. L'identificador del curs correspon a el nombre de cursos actual + 1
  */
  void llegir_cursos(const Conjunt_sessions& sessions);

  /** @brief Operació d'escriptura de cursos
      \pre Cert
      \post Per a cada curs ordenat per identificador es mostra pel canal de sortida estandard les vegades completat, el nombre d'inscrits, el nombre de sessions i la seqüència d'identificadors de les sessions per ordre que es van llegir
  */
  void escriure_cursos() const;

  /** @brief Operació d'escriptura d'un curs
      \pre Cert
      \post Es mostra pel canal de sortida estandard les vegades completat, el nombre d'inscrits, el nombre de sessions i la seqüència d'identificadors de les sessions per ordre que es van llegir el curs amb identificador c
  */
  void escriure_curs(int c) const;

};
#endif
