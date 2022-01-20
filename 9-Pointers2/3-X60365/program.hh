/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
bool buscar(const T& x) const {
  if (primer_node == NULL) return false;
  else return i_buscar(primer_node, x);
}

bool i_buscar(node_arbreGen* node, const T& x) const {
  if (node->info == x) return true;
  for (int i = 0; i < node->seg.size(); ++i) {
    if (node->seg[i] != NULL) {
      bool b = i_buscar(node->seg[i], x);
      if (b) return true;
    }
  }
  return false;
}
