#include "BinTreeIOEst.hh"

void read_bintree_est(BinTree<Estudiant>& a) {
  Estudiant est_in;
  est_in.llegir();
  if (est_in.consultar_DNI() != 0 or est_in.consultar_nota() != 0) {
    BinTree<Estudiant> esquerra;
    read_bintree_est(esquerra);
    BinTree<Estudiant> dreta;
    read_bintree_est(dreta);
    a = BinTree<Estudiant> (est_in, esquerra, dreta);
  }
}
