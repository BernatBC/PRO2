#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
  map<string, int> dic;
  char instruccio;
  while (cin >> instruccio) {
    string clau;
    cin >> clau;
    if (instruccio == 'a') ++dic[clau];
    else if (instruccio == 'f') {
      map<string, int>::const_iterator it = dic.find(clau);
      if (it != dic.end()) cout << it->second << endl;
      else cout << 0 << endl;
    }
    else {
      if (dic[clau] > 0) --dic[clau];
    }
  }
}
