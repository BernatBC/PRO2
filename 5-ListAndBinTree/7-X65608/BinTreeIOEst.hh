#ifndef BIN_TREE_IO_EST_HH
#define BIN_TREE_IO_EST_HH

#include "BinTree.hh"
#include "Estudiant.hh"
using namespace std;

void read_bintree_est(BinTree<Estudiant>& a);
// Pre: a és buit; el canal estandar d’entrada conté una seqüència
// de parells <int, double> que representa un arbre binari d’estudiants
// en preordre, on un parell amb l’int = ‘‘marca’’ representa
// un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada

#endif
