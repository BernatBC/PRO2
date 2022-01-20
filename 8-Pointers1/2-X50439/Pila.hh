#ifndef PILA
#define PILA

#include "utils.PRO2"


template <class T> class Pila {

private:
  struct node_pila {
    T info;
    node_pila* seguent;
  }; 
 
  int altura;
  node_pila* primer_node;


static void esborra_node_pila(node_pila* m) 
    /* Pre: cert */
    /* Post: no fa res si m és NULL, en cas contrari, allibera espai
       dels nodes de la cadena que té el node apuntat per m com a
       primer */
  {  
    if (m != NULL) {
      esborra_node_pila(m->seguent);
      delete m;
    }
  }

 void esborra_node_pila_it(node_pila* m){
    while(m!=NULL){
      node_pila* n=m->seguent;
      delete m;
      m=n;
    }
  }

public:

  Pila() 
    /* Pre: cert */
    /* Post: El resultat és una pila sense cap element */
  {
    altura= 0;
    primer_node= NULL;
  }

  
  Pila(const Pila& original) 
    /* Pre: cert */
    /* Post: El resultat és una còpia d'original */
  {
    altura= original.altura;
    primer_node = copia_node_pila_it(original.primer_node);
  }
  

  ~Pila() 
    // Destructora: Esborra automàticament els objectes locals en
    // sortir d'un àmbit de visibilitat
  {
    esborra_node_pila_it(primer_node);
  }


  void p_buida() 
    /* Pre: cert */
    /* Post: El p.i. passa a ser una pila sense elements i qualsevol
       contingut anterior del p.i. ha estat esborrat */
{
    esborra_node_pila_it(primer_node);
    altura= 0;
    primer_node= NULL;
  }
        
  void empilar (const T& x) 
    /* Pre: cert */
    /* Post: El p.i. és com el p.i. original amb x afegit
       com a darrer element */
  {
    node_pila* aux;
    aux= new node_pila; // reserva espai pel nou element
    aux->info= x;
    aux->seguent= primer_node;
    primer_node= aux;
    ++altura;
  }

  void desempilar () 
    /* Pre: el p.i. és una pila no buida (<=> primer_node != NULL) */ 
    /* Post: El p.i. és com el p.i. original però sense el darrer
       element afegit al p.i. original */
  {
    node_pila* aux;
    aux= primer_node; // conserva l'accés al primer node abans
    //   d'avançar
    primer_node= primer_node->seguent; // avança
    delete aux; // allibera l'espai de l'antic cim
    --altura;
  }

  T cim() const 
    /* Pre: el p.i. és una pila no buida (<=> primer_node != NULL) */
    /* Post: el resultat és el darrer element afegit al p.i. */ 
  { 
    return primer_node->info;
  }

  bool es_buida() const 
    /* Pre: cert */
    /* Post: El resultat indica si el p.i. és una pila buida o no */
  {
    return primer_node==NULL;
  }

  int mida() const 
    /* Pre: cert */
    /* Post: El resultat és el nombre d'elements del p.i. */
  {
    return altura;
  }

 #include "program.hh"
};

#endif
