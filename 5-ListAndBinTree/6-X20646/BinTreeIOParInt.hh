#ifndef BIN_TREE_IO_PAR_INT_HH
#define BIN_TREE_IO_PAR_INT_HH

#include <iostream>
#include "BinTree.hh"
#include "ParInt.hh"
using namespace std;

void read_bintree_parint(BinTree<ParInt>& a);
// Pre: a és buit; el canal estandar d’entrada conté un nombre
// parell d’enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada

//void write_bintree_parint(const BinTree<ParInt>& a);
// Pre: a = A
// Post: s’han escrit al canal estandar de sortida els elements
// d’a recorrreguts en inordre, a = A

#endif
