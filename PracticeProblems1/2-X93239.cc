#include <iostream>
#include <vector>
using namespace std;

int comptatge_frontisses(const vector<int> &v) {
  int frontissa = 0;
  int suma1 = 0;
  int suma2 = 0;
  for (int i = 0; i < v.size(); ++i) {
    suma2 += v[i];
  }
  for (int i = 0; i < v.size(); ++i) {
    suma2 -= v[i];
    if (suma2 - suma1 == v[i]) ++frontissa;
    suma1 += v[i];
  }
  return frontissa;
}
/*
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << comptatge_frontisses(v) << endl;
}
*/
