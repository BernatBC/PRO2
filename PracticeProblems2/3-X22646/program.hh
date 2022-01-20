/* Pre: p.i. = C1, c = C2 */
/* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
void trenat(Cua &c) {
  if (longitud == 0 and c.longitud == 0) {
    longitud = 0;
    primer_node = NULL;
    ultim_node = NULL;
  }
  else if (longitud == 0 and c.longitud != 0) {
    longitud = c.longitud;
    primer_node = c.primer_node;
    ultim_node = c.ultim_node;
  }
  else if (longitud != 0 and c.longitud == 0) {

  }
  else {
    longitud += c.longitud;
    node_cua* c1 = primer_node;
    node_cua* c2 = c.primer_node;
    while (c1 != NULL and c2 != NULL) {
      node_cua* c1s = c1->seguent;
      node_cua* c2s = c2->seguent;
      c2->seguent = c1->seguent;
      c1->seguent = c2;
      if (c1s == NULL) c2->seguent = c2s;
      c1 = c1s;
      c2 = c2s;
    }
  }
  c.longitud = 0;
  c.primer_node = NULL;
  c.ultim_node = NULL;
}
