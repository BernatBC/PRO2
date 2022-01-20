/** @file Conjunt_usuaris.hh
    @brief Especificació de la classe Conjunt_usuaris
*/
#ifndef CONJUNT_USUARIS_HH
#define CONJUNT_USUARIS_HH

#include "Usuari.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

/** @class Conjunt_usuaris
    @brief Representa el conjunt de característiques i operacions del conjunt d'usuaris.
*/
class Conjunt_usuaris {
private:
  /**@brief map d'usuaris*/
  map<string, Usuari> usuaris;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea un conjunt_usuaris buit
  */
  Conjunt_usuaris();

  //Modificadores

  /** @brief Modificadora de l'addició d'un usuari
      \pre L'usuari amb identificador u no pertany al conjunt
      \post Afageix un usuari amb identificador u al conjunt
  */
  void afegir_usuari(string u);

  /** @brief Modificadora de l'eliminació d'un usuari
      \pre L'usuari amb identificador u pertany al conjunt
      \post Elimina l'usuari amb identificador u del conjunt
  */
  void eliminar_usuari(string u);

  /** @brief Modificadora de l'inscripció d'un curs en un usuari
      \pre Existeix el curs amb identificador c a cursos i l'usuari amb identificador u pertany al conjunt i l'usuari no està inscrit en cap curs
      \post Inscriu l'usuari amb identificador u al curs amb identificador c
  */
  void inscriure(string u, int c, Colleccio_cursos& cursos, const Conjunt_sessions& sessions);

  /** @brief Modificadora del nombre d'enviaments i de vegades completat
      \pre Cert
      \post Afageix en l'usuari amb identificador u un enviament en el problema amb identificador p correcte si resolt és cert, incorrecte altrament i actualitza els problemes disponibles
  */
  void enviament(string u, string p, int r, const Conjunt_sessions& sessions, Colleccio_cursos& cursos);

  //Consultores

  /** @brief Consultora del nombre d'usuaris
      \pre Cert
      \post El resultat és el nombre d'usuaris continguts al conjunt
  */
  int consultar_n_usuaris() const;

  /** @brief Consultora del curs d'un usuari
      \pre Existeix l'usuari amb l'identificador u, i aquest està inscrit
      \post El resultat és l'identificador del curs en el qual l'usuari amb identificador u està inscrit
  */
  int consultar_curs(string u) const;

  /** @brief Consultora de l'existència d'un usuari
      \pre Cert
      \post El resultat és cert si l'usuari amb identificador u està contingut en el conjunt, fals altrament
  */
  bool existeix(string u) const;

  /** @brief Consultora de l'inscripció d'un usuari
      \pre L'usauri amb identificador u pertany al conjunt
      \post El resultat és cert si l'usuari amb identificador u està inscrit en un curs, fals altrament
  */
  bool inscrit(string u) const;

  //Lectura i escriptura

  /** @brief Operació de lectura d'usuaris
      \pre Cert
      \post Es llegeix pel canal d'entrada el nombre d'usuaris i una seqüència d'identificadors d'usuaris
  */
  void llegir_usuaris();

  /** @brief Operació d'escriptura dels problemes resolts
      \pre L'usauri amb identificador u pertany al conjunt
      \post Es mostra pel canal de sortida estandard l'identificador i el nombre d'enviaments totals dels problemes resolts per ordre creixent de l'identificador, de l'usuariamb identificador u
  */
  void escriure_problemes_resolts(string u) const;

  /** @brief Operació d'escriptura dels problemes disponibles
      \pre L'usauri amb identificador u pertany al conjunt
      \post Es mostra pel canal de sortida estandard l'identificador i el nombre d'enviaments totals dels problemes disponibles per ordre creixent de l'identificador, de l'usuariamb identificador u
  */
  void escriure_problemes_disponibles(string u) const;

  /** @brief Operació d'escriptura d'usuaris
      \pre Cert
      \post Es mostra pel canal de sortida estandard els enviaments totals, el nombre de problemes resolts, el nombre de problemes intentats i l'identificador del curs inscrit (0 si no està inscrit en cap curs) dels usuaris ordenats creixentment per l'identificador
  */
  void escriure_usuaris() const;

  /** @brief Operació d'escriptura d'un usuari
      \pre L'usauri amb identificador u pertany al conjunt
      \post Es mostra pel canal de sortida estandard els enviaments totals, el nombre de problemes resolts, el nombre de problemes intentats i l'identificador del curs inscrit (0 si no està inscrit en cap curs) de l'usuari amb identificador u
  */
  void escriure_usuari(string u) const;

};
#endif
