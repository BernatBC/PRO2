#include <iostream>
#include "Cjt_estudiants.hh"
using namespace std;

int main() {
    
    Cjt_estudiants estudiants1;
    
    estudiants1.llegir();
    cout << "Read" << endl; 
    cout << "Max: " <<endl;
    Estudiant est = estudiants1.estudiant_nota_max();
    est.escriure();
    cout << "List:" << endl;
    estudiants1.escriure();
    
}
