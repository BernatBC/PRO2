#include <iostream>
#include <vector>
using namespace std;

int solitaris(const vector<int> &v) {
  int sol = 0;
  for (int i = 0; i < v.size(); ++i) {
    if ((i == 0 or v[i - 1] != v[i]) and (i == v.size() - 1 or v[i] != v[i + 1])) ++sol;
  }
  return sol;
}
/*
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << solitaris(v) << endl;
}
*/
