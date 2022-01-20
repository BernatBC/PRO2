#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
//Pre: valor de nota compresa entre el 0 i el 10
//Post: retorna valor de la nota arrodonida amb un decimal (si la nota no es entera)
double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
}

int main() {
    
    int opcio;
    Cjt_estudiants estudiants;
    
    estudiants.llegir();
    
    while (cin >> opcio and opcio != -6) {
        
        //Afegir estudiant
        if (opcio == -1) {
            Estudiant est1;
            est1.llegir();
            
            if (not estudiants.existeix_estudiant(est1.consultar_DNI())) {
                   if (estudiants.mida() < estudiants.mida_maxima()) {
                        estudiants.afegir_estudiant(est1);
                    }
                    else {
                        cout << "el conjunto esta lleno" <<endl;
                        cout << endl;
                    }
                }
                else {
                    cout << "el estudiante " << est1.consultar_DNI() << " ya estaba" << endl;
                    cout << endl;
                }
            
            
        }
        //Consultar nota estudiant
        else if (opcio == -2) {
            int dni;
            cin >> dni;
            
            if (estudiants.existeix_estudiant(dni)) {
                
                Estudiant est2 = estudiants.consultar_estudiant(dni);
                
                if (est2.te_nota()) {
                    cout << "el estudiante " << dni << " tiene nota " << est2.consultar_nota() << endl;
                    cout << endl;
                }
                else {
                    cout << "el estudiante " << dni << " no tiene nota" << endl;
                    cout << endl;
                }
                
            }
            else {
                cout << "el estudiante " << dni << " no esta" << endl;
                cout << endl;
            }
            
        }
        //Modificar nota estudiant
        else if (opcio == -3) {
            
            Estudiant est3;
            est3.llegir();
            
            if (estudiants.existeix_estudiant(est3.consultar_DNI())) {
                
                estudiants.modificar_estudiant(est3);
                
            }
            else {
                cout << "el estudiante " << est3.consultar_DNI() << " no esta" << endl;
                cout << endl;
            }
            
        }
        //Arrodonir notes conjunt estudiants
        else if (opcio == -4) {
            
            for (int i = 1; i <= estudiants.mida(); ++i) {
                Estudiant est4 = estudiants.consultar_iessim(i);
                
                if (est4.te_nota()) {
                
                double nota = est4.consultar_nota();
                double notared = redondear(nota);
                est4.modificar_nota(notared);
                estudiants.modificar_estudiant(est4);
                }
            }
            
        }
        //Escriure conjunt estudiants
        else if (opcio == -5) {
            estudiants.escriure();
            cout << endl;
        }
        
    }
    
}
