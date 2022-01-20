 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
void esborrar_tots(const T& x) {
  node_llista* n = primer_node;
  while(n != NULL) {
    if (n->info == x) {
      if (n == primer_node and n == ultim_node) {
        primer_node = NULL;
        ultim_node = NULL;
      }
      else if (n == primer_node) {
        primer_node = n->seg;
        (n->seg)->ant = NULL;
      }
      else if (n == ultim_node) {
        ultim_node = n->ant;
        (n->ant)->seg = NULL;
      }
      else {
        (n->seg)->ant = n->ant;
        (n->ant)->seg = n->seg;
      }
      if (act == n) act = n->seg;
      node_llista* aux = n;
      n = n->seg;
      delete aux;
      --longitud;
    }
    else n = n->seg;
  }
}
