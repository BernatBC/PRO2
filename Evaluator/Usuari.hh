/** @file Usuari.hh
    @brief Especificació de la classe Usuari
*/
#ifndef USUARI_HH
#define USUARI_HH

#include "Conjunt_problemes.hh"
#include "Colleccio_cursos.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <set>
#endif

/** @class Usuari
    @brief Representa el conjunt de característiques i operacions d'usuaris.

    Fem ús d'una estructura de dades que emmagatzema les sessions cursades per ser més eficients de temps en operacions com inscriure
*/

class Usuari {
private:
  /**@brief Nombre d'enviaments totals*/
  int enviaments;
  /**@brief Nombre de problemes en el qual s'ha fet mínim un enviament*/
  int intentats;
  /**@brief Identificador del curs inscrit*/
  int curs;
  /**@breif conjunt de sessions completades*/
  set<string> sessions_resoltes;
  /**@brief Conjunt de problemes resolts*/
  Conjunt_problemes resolts;
  /**@brief Conjunt de problemes disponibles*/
  Conjunt_problemes disponibles;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea una usuari buit
  */
  Usuari();

  //Modificadores

  /** @brief Modificadora de l'inscripció d'un curs
      \pre Usuari no inscrit (curs = 0)
      \post Inscriu l'usuari en el curs amb identificador c i actualitza els problemes disponibles
  */
  void inscriure(int c, Colleccio_cursos& cursos, const Conjunt_sessions& sessions);

  /** @brief Modificadora de la resolució de problemes
      \pre Cert
      \post Afageix un enviament en el problema amb l'identificador p correcte si resolt és cert, incorrecte altrament i actualitza els problemes disponibles
  */
  void enviament(string p, bool resolt, const Conjunt_sessions& sessions, Colleccio_cursos& cursos);

  //Consultores

  /** @brief Consultora de l'identificador del curs
      \pre inscrit
      \post El resultat és l'identificador del curs inscrit
  */
  int consultar_curs() const;

  /** @brief Consultora de si està incrit en algun curs
      \pre Cert
      \post El resultat és cert si l'usuari està inscrit, fals altrament
  */
  bool inscrit() const;


  //Lectura i escriptura

  /** @brief Operació d'escriptura dels problemes resolts
      \pre Cert
      \post Es mostra pel canal de sortida estandard l'identificador i el nombre d'enviaments totals dels problemes resolts per ordre creixent de l'identificador
  */
  void escriure_resolts() const;

  /** @brief Operació d'escriptura dels problemes disponibles
      \pre Cert
      \post Es mostra pel canal de sortida estandard l'identificador i el nombre d'enviaments totals dels problemes disponibles per ordre creixent de l'identificador
  */
  void escriure_disponibles() const;

  /** @brief Operació d'escriptura d'un usuari
      \pre Cert
      \post Es mostra pel canal de sortida estandard els enviaments totals, el nombre de problemes resolts, el nombre de problemes intentats i l'identificador del curs inscrit (0 si no està inscrit en cap curs)
  */
  void escriure_usuari() const;

};

#endif
