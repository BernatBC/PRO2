#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int n, x;
    cin >> n >> x;
    
    for (int i = 0; i < n; ++i) {
        
        int suma = 0;
        int num;
        
        while (cin >> num and num != x) {
            suma += num;
        }
        
        string s;
        getline(cin, s);
        
        cout << "La suma de la secuencia " << i + 1 << " es " << suma <<endl; 
        
    }
    
}
