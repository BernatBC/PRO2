#include "Estudiant.hh"
#include <vector>

 /* Pre: v no conte repeticions de dni  */
 pair<int,int>  max_min_vest(const vector<Estudiant>& v) {
     
     int mida = v.size();
     pair<int, int> posicio;
     
     Estudiant est_max;
     Estudiant est_min;
     
     double max = -1;
     double min = 11;
     
     posicio.first = -1;
     posicio.second = -1;
     
     for (int i = 0; i < mida; ++i) {
         
         if (v[i].te_nota()) {
             double nota = v[i].consultar_nota();
             double nota_max;
             double nota_min;
             
             
             if (max != -1 and min != 11) {
                 nota_max = est_max.consultar_nota();
                nota_min = est_min.consultar_nota();
            }
            else {
                nota_max = max;
                nota_min = min;
            }
             
             if (nota < nota_min or (nota == nota_min and v[i].consultar_DNI() < est_min.consultar_DNI())) {
                 est_min = v[i];
                 min = nota;
                 posicio.second = i;
            }
            
            if (nota > nota_max or (nota == nota_max and v[i].consultar_DNI() < est_max.consultar_DNI())) {
                 est_max = v[i];
                 max = nota;
                 posicio.first = i;
            }
             
        }
         
    }
     return posicio;
}
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */

/*
int main() {
    
    int size;
    cin >> size;
    
    vector<Estudiant> v(size);
    
    for (int i = 0; i < size; ++i) {
        v[i].llegir();
    }
    
    pair<int, int> a = max_min_vest(v);
    
    cout << a.first << " " << a.second << endl;
    
}*/
