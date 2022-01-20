/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
int freq(const T& x) const {
  if (primer_node == NULL) return 0;
  else return i_freq(primer_node, x);
}

int i_freq(node_arbreGen* node, const T& x) const {
  int fre = 0;
  if (node->info == x) ++fre;
  for (int i = 0; i < node->seg.size(); ++i) {
    if (node->seg[i] != NULL) {
      fre += i_freq(node->seg[i], x);
    }
  }
  return fre;
}
