#include "Estudiant.hh"
#include <iostream>
#include <vector>

int main() {
    
    int n_estudiants, n_assignatures, n_selec;
    cin >> n_estudiants >> n_assignatures >> n_selec;
    
    vector<int> assig(n_selec);
    
    //Obtenir assignatures seleccionades
    for (int i = 0; i < n_selec; ++i) {
        cin >> assig[i];
    }
    
    for (int i = 0; i < n_estudiants; ++i) {
        int dni;
        cin >> dni;
        double mitjana = 0;
        
        for (int j = 1; j <= n_assignatures; ++j) {
            
            double nota_assig;
            cin >> nota_assig;
            
            for (int k = 0; k < assig.size(); ++k) {
                if (assig[k] == j) {
                    mitjana += nota_assig;
                }
            }
            
        }
        
        //Mostrar DNI i nota mitjana
        mitjana = mitjana/n_selec;
        cout << dni << " " << mitjana <<endl;
    }
    
}
