#include "Estudiant.hh"
#include <iostream>
#include <vector>

 /* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
void simplificar_vector(vector<Estudiant>& v, int& pos) {
    
    int mida = v.size();
    int n_estudiants = 0;
    
    for (int i = 1; i < mida; ++i) {

        if (v[i].consultar_DNI() == v[n_estudiants].consultar_DNI()) {
            
            if (not v[n_estudiants].te_nota() and v[i].te_nota()) {
                v[n_estudiants].afegir_nota(v[i].consultar_nota());
            }
            else if (v[n_estudiants].te_nota() and v[i].te_nota() and v[i].consultar_nota() > v[n_estudiants].consultar_nota()) {
                v[n_estudiants].modificar_nota(v[i].consultar_nota());
            }
            
        }
        else {
            v[n_estudiants + 1] = v[i];
            ++n_estudiants;
        }
        
    }
    
    pos = n_estudiants;
    
}
 /* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
 /*
 int main() {
     
     int n;
     cin >> n;
     int pos = 0;
     vector<Estudiant> v(n);
     
     for (int i = 0; i < n; ++i) {
         v[i].llegir();
    }

     simplificar_vector(v, pos);
     
     for (int i = 0; i < v.size(); ++i) {
         v[i].escriure();
    }
    cout << pos << endl;
}*/
