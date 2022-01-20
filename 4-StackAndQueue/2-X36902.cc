#include <iostream>
#include <stack>
using namespace std;

int main() {

  char parentesi_in;
  stack<char> pila;
  bool correcte = true;

  cin >> parentesi_in;

  while (correcte and parentesi_in != '.') {

    if (parentesi_in == '(' or parentesi_in == '[') {
      pila.push(parentesi_in);
    }
    else {

      if (pila.empty()) {
        correcte = false;
      }
      else if ((parentesi_in == ')' and pila.top() == '(') or (parentesi_in == ']' and pila.top() == '[')) {
        pila.pop();
      }
      else {
        correcte = false;
      }

    }

    cin >> parentesi_in;
  }

  if (correcte and pila.empty()) {
    cout << "Correcte" << endl;
  }
  else {
    cout << "Incorrecte" << endl;
  }

}