/* Pre: cert */
/* Post: si m és NULL, el resultat és NULL; en cas contrari, el
       resultat apunta al primer node d'una cadena de nodes que són
       còpia de de la cadena que té el node apuntat per m com a primer */
node_pila* copia_node_pila_it(node_pila* m) {
  if (m == NULL) return NULL;
  node_pila* primer = new node_pila;
  node_pila* act = primer;
  act->info = m->info;
  m = m->seguent;
  while (m != NULL) {
    act->seguent = new node_pila;
    act = act->seguent;
    act->info = m->info;
    m = m->seguent;
  }
  act->seguent = NULL;
  return primer;
}

 /* Pre: cert */
 /* Post: El p.i. passa a ser una còpia d'original i qualsevol
          contingut anterior del p.i. ha estat esborrat (excepte si el
          p.i. i original ja eren el mateix objecte) */
Pila& operator=(const Pila& original) {
  if (this != &original) {
    altura = original.altura;
    esborra_node_pila(primer_node);
    primer_node = copia_node_pila_it(original.primer_node);
  }
  return *this;
}
