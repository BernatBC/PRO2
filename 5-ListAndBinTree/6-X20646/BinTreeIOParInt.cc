#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a) {
  ParInt pair_in;
  bool b = pair_in.llegir();
  if (b) {
    BinTree<ParInt> esquerra;
    read_bintree_parint(esquerra);
    BinTree<ParInt> dreta;
    read_bintree_parint(dreta);
    a = BinTree<ParInt> (pair_in, esquerra, dreta);
  }
  else {
    a = BinTree<ParInt> (pair_in);
  }
}
/*
void write_bintree_parint(const BinTree<ParInt>& a) {

}
*/
