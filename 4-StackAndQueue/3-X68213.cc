#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void Afegir(stack<string> &pila, string llibre) {

  pila.push(llibre);

}

void Retirar(stack<string> &pila, int n) {

  while (not pila.empty() and n > 0) {
    pila.pop();
    --n;
  }

}

void Mostrar(stack<string> pila) {

  while (not pila.empty()) {
    cout << pila.top() << endl;
    pila.pop();
  }

}

int main() {

  int n_piles;
  cin >> n_piles;

  vector<stack<string>> biblioteca(n_piles);

  string opcio;
  cin >> opcio;

  while (opcio != "-4") {
    //Afegir llibre
    if (opcio == "-1") {
      int num_pila;
      string llibre;

      cin >> llibre >> num_pila;

      Afegir(biblioteca[num_pila - 1], llibre);

    }
    //Retirar llibres
    else if (opcio == "-2") {
      int num_llibres;
      int num_pila;

      cin >> num_llibres >> num_pila;

      Retirar(biblioteca[num_pila - 1], num_llibres);

    }
    //Mostrar pila
    else if (opcio == "-3") {
      int num_pila;
      cin >> num_pila;

      cout << "Pila de la categoria " << num_pila << endl;

      Mostrar(biblioteca[num_pila - 1]);

      cout << endl;
    }
    cin >> opcio;
  }

}