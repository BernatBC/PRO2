#include "Estudiant.hh"
#include <iostream>
#include <vector>

vector<Estudiant> lectura(int mida) {

    vector<Estudiant> v;
    
    for (int i = 0; i < mida; ++i) {
        
        Estudiant a;
        a.llegir();
        
        if (v.size() == 0) {
            v.push_back(a);
        }
        else if (v[v.size() - 1].consultar_DNI() == a.consultar_DNI()){
            
            if (not v[v.size() - 1].te_nota() or (a.te_nota() and a.consultar_nota() > v[v.size() - 1].consultar_nota()))
            
            v[v.size() - 1] = a;
        }
        else {
            v.push_back(a);
        }
        
    }
    return v;
}

int main() {
    
    int size;
    cin >> size;
    
    vector<Estudiant> v = lectura(size);
    
    int size2 = v.size();
    
    for (int i = 0; i < size2; ++i) {
        v[i].escriure();
    }
    
}
