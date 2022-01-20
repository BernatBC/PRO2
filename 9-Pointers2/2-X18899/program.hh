/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
void arbsuma(ArbreNari& asum) const {
  asum.N = N;
  asum.primer_node = suma(primer_node);
}

static node_arbreNari* suma(node_arbreNari* m) {
  if (m == NULL) return NULL;
  node_arbreNari* n = new node_arbreNari;
  int s = m->info;
  for (int i = 0; i < m->seg.size(); ++i) {
    node_arbreNari* fill = suma(m->seg[i]);
    n->seg.push_back(fill);
    if (fill != NULL) s += fill->info;
  }
  n->info = s;
  return n;
}
