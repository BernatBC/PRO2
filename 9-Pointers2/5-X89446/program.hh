/* Pre: cert */
/* Post: el resultat és una llista que conté els mateixos
elements que el p.i. tal que tots els més petits o iguals
que x al p.i. precedeixen als més grans que x al p.i. però
sempre respectant l'ordre que hi havia entre ells al p.i.
L'element actual de la llista retornada és el primer dels
més grans que x, si existeix, sinó es situa a la detra del
tot. El p.i. no es modifica */
Llista  reorganitzar_out(const T& x) const {
  Llista l;
  if (longitud == 0) return l;

  node_llista* ult_men = NULL;
  l.act = l.ultim_node = l.primer_node = NULL;
  l.longitud = longitud;
  node_llista* m  = new node_llista;

  while (m != NULL) {
    if (m->info <= x) {
      //m passa a darrer de petits
      if (ult_men == NULL) {
        ult_men = new node_llista;
        l.primer_node = ult_men;
        l.primer_node->ant = NULL;
      }
      else {
        ult_men->seg = new node_llista;
        ult_men->seg->ant = ult_men;
        ult_men = ult_men->seg;
      }
      ult_men->info = m->info;
    }
    else {
      //m passa a darrer de majors
      if (l.ultim_node == NULL) {
        l.ultim_node = new node_llista;
        l.act = l.ultim_node;
        l.act->ant = NULL;
      }
      else {
        l.ultim_node->seg = new node_llista;
        l.ultim_node->seg->ant = l.ultim_node;
        l.ultim_node = l.ultim_node->seg;
      }
      l.ultim_node->info = m->info;
    }
    m = m->seg;
  }
  //menors buit
  if (l.primer_node == NULL) {
    l.primer_node = l.act;
  }
  //majors buit
  else if (l.act == NULL) {
    l.ultim_node = ult_men;
  }
  //cap buida
  else {
    ult_men->seg = l.act;
    l.act->ant = ult_men;
  }
  l.ultim_node->seg = NULL;
  return l;
}
