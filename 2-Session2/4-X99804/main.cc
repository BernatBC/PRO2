#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>

bool comp(const Estudiant &a, const Estudiant &b) {
    
    if (a.consultar_nota() == b.consultar_nota()) {
        return a.consultar_DNI() < b.consultar_DNI();
    }
    
    return a.consultar_nota() > b.consultar_nota();
}

int main() {
    
    int n_estudiants, n_assignatures, n_selec;
    cin >> n_estudiants >> n_assignatures >> n_selec;
    
    vector<int> assig(n_selec);
    
    //Obtenir assignatures seleccionades
    for (int i = 0; i < n_selec; ++i) {
        cin >> assig[i];
    }
    
    vector<Estudiant> v(n_estudiants);
    
    for (int i = 0; i < n_estudiants; ++i) {
        
        Estudiant est1;
        
        est1.llegir();
        
        double mitjana = 0;
        
        for (int k = 0; k < assig.size(); ++k) {
            if (assig[k] == 1) {
                    mitjana += est1.consultar_nota();
            }
        }

        for (int j = 2; j <= n_assignatures; ++j) {
            
            double nota_assig;
            cin >> nota_assig;
            
            for (int k = 0; k < assig.size(); ++k) {
                if (assig[k] == j) {
                    mitjana += nota_assig;
                }
            }
            
        }
        
        mitjana = mitjana/n_selec;
        
        est1.modificar_nota(mitjana);
        v[i] = est1;
    }
    
    sort(v.begin(), v.end(), comp);
    
    for (int i = 0; i < n_estudiants; ++i) {
        v[i].escriure();
    }
    
}
