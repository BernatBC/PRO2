#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>

int main() {
    
    Cjt_estudiants conj1;
    Cjt_estudiants conj2;
    conj1.llegir();
    conj2.llegir();
    
    for (int i = 1; i <= conj1.mida(); ++i) {
        
        Estudiant est1 = conj1.consultar_iessim(i);
        Estudiant est2 = conj2.consultar_iessim(i);
        
        if (not est1.te_nota() or (est2.te_nota() and est2.consultar_nota() > est1.consultar_nota())) {
            
            conj1.modificar_estudiant(est2);
            
        }
        
    }
    
    conj1.escriure();
}
