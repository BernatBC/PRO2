/** @file Sessio.hh
    @brief Especificació de la classe Sessio
*/
#ifndef SESSIO_HH
#define SESSIO_HH

#include "Conjunt_problemes.hh"
#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <map>
#endif

using namespace std;

/** @class Sessio
    @brief Representa el conjunt de característiques i operacions de sessions.

    Per poder representar els problemes en forma de prerrequisits fem ús de BinTree com a estructura de dades.
    Fem ús d'una altra estructura de dades per poder ser més eficients de temps en operacions com actualitzar_disponibles
*/

class Sessio {
private:
  /**@brief identificador de la sessió*/
  string id;
  /**@brief Problemes de la sessió organitzats per prerrequisits*/
  BinTree<string> problemes;
  /**@brief map de cada problema de la sessió amb els problemes que tenen com a prerrequisit el problema de la clau del map*/
  map<string, BinTree<string>> map_problemes;

  /** @brief Consultora de problemes disponibles
      \pre Cert
      \post S'afageixen a disponibles tots els problemes de la sessió tals que no estiguin a resolts ni a disponibles. Completat serà fals si s'ha afegit mínim un problema a disponibles, cert altrament.
  */
  void disponibles_bintree(const BinTree<string>& arbre, const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, bool& completat) const;

  /** @brief Operació de lectura d'una sessió
      \pre Cert
      \post Es llegeix pel canal d'entrada la seqüència de problemes en preordre que corresponen a la sessió
  */
  void lectura_bintree(BinTree<string>& arbre);

  /** @brief Operació d'escriptura d'una sessió
      \pre Cert
      \post Es mostra pel canal de sortida la seqüència de problemes estructurats en preordre que pertanyen a la sessió
  */
  void escriptura_bintree(const BinTree<string>& arbre) const;


public:
  //Constructores

  /** @brief Constructora per defecte
      \pre Cert
      \post Crea una sessió buida
  */
  Sessio();

  /** @brief Constructora amb identificador
      \pre Cert
      \post Crea una sessió buida amb l'identificador s
  */
  Sessio(string s);

  //Consultores

  /** @brief Consultora de l'identificador
      \pre Cert
      \post El resultat és l'identificador del problema
  */
  string consultar_id() const;

  /** @brief Consultora del nombre de problemes d'una sessió
      \pre Cert
      \post El resultat és el nombre de problemes de la sessió
  */
  int consultar_n_problemes() const;

  /** @brief Consultora de problemes disponibles
      \pre Cert
      \post S'afageixen a disponibles tots els problemes de la sessió tals que no estiguin a resolts ni a disponibles. El resultat serà fals si s'ha afegit mínim un problema a disponibles, cert altrament.
  */
  bool problemes_disponibles(const Conjunt_problemes& resolts, Conjunt_problemes& disponibles) const;

  /** @brief Consultora de problemes disponibles
      \pre El problema amb identificador p pertany a la sessió
      \post S'afageixen a disponibles els problemes de la sessió tals que no estiguin a resolts ni a disponibles i que tinguin com a prerrequisit el problema amb identificador p. El resultat serà fals si s'ha afegit mínim un problema a disponibles, cert altrament.
  */
  bool actualitzar_disponibles(const Conjunt_problemes& resolts, Conjunt_problemes& disponibles, string p) const;

  /** @brief Consultora de problemes-sessio
      \pre Cert
      \post S'afageix al map cada l'identificador (com a clau) de cada problema amb l'identificador de la sessió
  */
  void recorre_sessio(map<string,string>& sessions_problemes, string s) const;

  //Lectura i escriptura

  /** @brief Operació de lectura d'una sessió
      \pre Entrada vàlida
      \post Es llegeix pel canal d'entrada l'identificador de la sessió i una seqüència de problemes en preordre
  */
  void llegir_sessio();

  /** @brief Operació d'escriptura d'una sessió'
      \pre Cert
      \post Es mostra pel canal de sortida estandard els problemes continguts a la sessio en preordre de prerrequisits
  */
  void escriure_sessio() const;
};

#endif
