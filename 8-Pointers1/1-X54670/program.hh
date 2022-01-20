/* Pre: c=C */
/* Post: el p.i. passa a ser la concatenació de C al paràmetre implícit, c és buida */
void concat(Cua &c) {
  if (c.longitud > 0) {
    if (longitud == 0) {
      primer_node = c.primer_node;
      ultim_node = c.ultim_node;
    }
    else {
      ultim_node->seguent = c.primer_node;
      ultim_node = c.ultim_node;
    }
    longitud += c.longitud;
    c.longitud = 0;
    c.primer_node = NULL;
    c.ultim_node = NULL; 
  }
}
