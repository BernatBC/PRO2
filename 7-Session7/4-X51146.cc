#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
  set<string> jugadors;
  string jugador;
  cin >> jugador;
  while (jugador != ".") {
    jugadors.insert(jugadors.end(), jugador);
    cin >> jugador;
  }

  int num;
  cin >> num;
  set<string> buit = jugadors;
  for (int i = 0; i < num; ++i) {
    set<string> activitat = jugadors;
    cin >> jugador;
    while (jugador != ".") {
      activitat.erase(jugador);
      buit.erase(jugador);
      cin >> jugador;
    }
    set<string>::iterator it = activitat.begin();
    while (it != activitat.end()) {
      jugadors.erase(*it);
      ++it;
    }
  }

  cout << "Totes les activitats:";
  set<string>::const_iterator it = jugadors.begin();
  while (it != jugadors.end()) {
    cout << " " << *it;
    ++it;
  }
  cout << endl;
  cout << "Cap activitat:";
  it = buit.begin();
  while (it != buit.end()) {
    cout << " " << *it;
    ++it;
  }
  cout << endl;
}
