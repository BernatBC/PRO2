/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */
void arb_sumes(Arbre<int> &asum) const {
  asum.primer_node = suma(primer_node);
}

static node_arbre* suma(node_arbre* m) {
  if (m != NULL) {
    node_arbre* n = new node_arbre;
    n->segE = suma(m->segE);
    n->segD = suma(m->segD);
    int e = 0;
    int d = 0;
    if (n->segE != NULL) e = (n->segE)->info;
    if (n->segD != NULL) d = (n->segD)->info;
    n->info = m->info + e + d;
    return n;
  }
  return NULL;
}
