/** @file Conjunt_sessions.hh
    @brief Especificació de la classe Conjunt_sessions
*/
#ifndef CONJUNT_SESSIONS_HH
#define CONJUNT_SESSIONS_HH

#include "Sessio.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

/** @class Conjunt_sessions
    @brief Representa el conjunt de característiques i operacions del conjunt de sessions.
*/

class Conjunt_sessions {
private:
  /**@brief map que conté sessions*/
  map<string, Sessio> sessions;

public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea un conjunt_sessions buit
  */
  Conjunt_sessions();

  //Modificadores

  /** @brief Modificadora de l'addició d'una sessio
      \pre No hi ha cap sessió al conjunt amb el mateix identificador que la sessió s
      \post Afageix la sessió s al conjunt
  */
  void afegir_sessio(const Sessio& s);

  //Consultores

  /** @brief Consultora del nombre de sessions
      \pre Cert
      \post El resultat és el nombre de sessions continguts al conjunt
  */
  int consultar_n_sessions() const;

  /** @brief Consultora del nombre de problemes d'una sessió
      \pre Existeix una sessió amb l'identificador s
      \post El resultat és el nombre de sessions continguts al conjunt
  */
  int consultar_n_problemes(string s) const;

  /** @brief Consultora de l'existència d'una sessió'
      \pre Cert
      \post El resultat és cert si la sessió amb identificador s està contingut en el conjunt, fals altrament
  */
  bool existeix(string s) const;

  /** @brief Consultora d'una sessió
      \pre Existeix una sessió amb l'identificador s
      \post El resultat és la sessió amb l'identificador s
  */
  Sessio consultar_sessio(string s) const;

  /** @brief Consultora de problemes disponibles
      \pre El problema amb identificador p pertany a la sessió amb identificador s
      \post S'afageixen a disponibles els problemes de la sessió amb identificador s tals que no estiguin a resolts ni a disponibles i que tinguin com a prerrequisit el problema amb identificador p. El resultat serà fals si s'ha afegit mínim un problema a disponibles, cert altrament.
  */
  bool actualitzar_disponibles(string s, const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, string p) const;

  /** @brief Consultora de problemes-sessio
      \pre Existeix una sessió amb l'identificador s
      \post S'afageix al map cada l'identificador (com a clau) de cada problema amb l'identificador de la sessió s
  */
  void recorre_sessio(string s, map<string, string>& sessions_problemes) const;

  //Lectura i escriptura

  /** @brief Operació de lectura de sessions
      \pre Entrada vàlida
      \post Es llegeix pel canal d'entrada el nombre de sessions i per a cada una l'identificador de la sessió i una seqüència de problemes en preordre
  */
  void llegir_sessions();

  /** @brief Operació d'escriptura d'una sessió
      \pre Cert
      \post Es mostra pel canal de sortida estandard per a cada sessió (ordenades per identificadors) el nombre de problemes de la sessio i els problemes continguts a la sessio en preordre de prerrequisits
  */
  void escriure_sessions() const;

  /** @brief Operació d'escriptura d'una sessió
      \pre La sessió amb identificador s pertany al conjunt
      \post Es mostra pel canal de sortida estandard el nombre de problemes de la sessio i els problemes continguts a la sessio en preordre de prerrequisits
  */
  void escriure_sessio(string s) const;

};
#endif
