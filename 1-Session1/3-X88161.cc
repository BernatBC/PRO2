#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Marcador{
    int a, b;
};

struct Taula{
    
    int equip, punts, gols_f, gols_c;
    
};

typedef vector<vector<Marcador>> Matriu;

//Ordena el vector per punts, diferencia de gols i per numero d'equip
bool classif(const Taula &a, const Taula &b){
    
    if (a.punts == b.punts) {
        if (a.gols_f - a.gols_c == b.gols_f - b.gols_c) {
            return a.equip < b.equip;
        }
        return a.gols_f - a.gols_c > b.gols_f - b.gols_c;
    }
    return a.punts > b.punts;
}

int main () {
    
    int n;
    cin >> n;
    
    //Obtenir matriu
    Matriu taula(n, vector<Marcador>(n));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> taula[i][j].a >> taula[i][j].b;
        }
    }
    
    //Agafar dades equips
    vector<Taula> lliga(n);
    
    for (int i = 0; i < n; ++i) {
        lliga[i].equip = i + 1;
        lliga[i].punts = 0;
        lliga[i].gols_f = 0;
        lliga[i].gols_c = 0;
        
        //Files
        for (int j = 0; j < n; ++j) {
            
            if (i != j) {
                lliga[i].gols_f += taula[i][j].a;
                lliga[i].gols_c += taula[i][j].b;
            
                if (taula[i][j].a == taula[i][j].b) {
                    lliga[i].punts += 1;
                }
                else if (taula[i][j].a > taula[i][j].b) {
                    lliga[i].punts += 3;
                }
            }
        }
        
        //Columnes
        for (int j = 0; j < n; ++j) {
            
            if (i != j) {
                
                lliga[i].gols_f += taula[j][i].b;
                lliga[i].gols_c += taula[j][i].a;
                
                if (taula[j][i].a == taula[j][i].b) {
                    lliga[i].punts += 1;
                }
                else if (taula[j][i].a < taula[j][i].b) {
                    lliga[i].punts += 3;
                }
                
            }

        }
        
    }
    
    //Ordena el vector per punts, diferencia de gols i per numero d'equip
    sort(lliga.begin(), lliga.end(), classif);
    
    //Mostrar resultats
    for (int i = 0; i < n; ++i) {
        cout << lliga[i].equip << " " << lliga[i].punts << " " << lliga[i].gols_f << " " << lliga[i].gols_c <<endl;
    }
    
}
