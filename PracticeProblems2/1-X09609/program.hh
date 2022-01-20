 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
void sub_arrel(Arbre& asub, const T& x) {
  asub.primer_node = NULL;
  int min_d = -1;
  cerca(primer_node, asub.primer_node, x, 0, min_d);
}

void cerca(node_arbre* n, node_arbre* &m, const T& x, int d, int& min_d) {
  if (n != NULL) {
    if (n->info == x and (d <= min_d or min_d == -1)) {
      min_d = d;
      m = copia_node_arbre(n);
    }
    else {
      cerca(n->segE, m, x, ++d, min_d);
      cerca(n->segD, m, x, ++d, min_d);
    }
  }
}

/* Pre: cert */
/* Post: el resultat es NULL si m es NULL; en cas contrari, el resultat apunta al node arrel d'una jerarquia de nodes que es una copia de la jerarquia de nodes que te el node apuntat per m com a arrel */
/*static node_arbre* copia_node_arbre(node_arbre* m) {
  if (m == NULL) return NULL;
  node_arbre* n = new node_arbre;
  n->segE = copia_node_arbre(m->segE);
  n->segD = copia_node_arbre(m->segD);
  n->info = m->info;
  return n;
}*/
