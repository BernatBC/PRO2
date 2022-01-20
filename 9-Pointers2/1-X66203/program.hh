/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
T maxim() const {
  return i_maxim(primer_node);
}

T i_maxim(node_arbreNari* node) const {
  T aux = node->info;
  for (int i = 0; i < N; ++i) {
    if (node->seg[i] != NULL) {
      T max_n = i_maxim(node->seg[i]);
      if (max_n > aux) aux = max_n;
    }
  }
  return aux;
}
