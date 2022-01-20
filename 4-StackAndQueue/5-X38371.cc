#include <iostream>
#include <queue>
using namespace std;

void Recalcular(queue<int> cua, int& min, int& max) {
	min = 1001;
	max = -1001;
	while (not cua.empty()) {
		int num = cua.front();
		if (num < min) min = num;
		if (num > max) max = num;
		cua.pop();
	}
}

int main() {
	int num;
	int min = 1001;
	int max = -1001;
	double suma = 0.0;
	int elements = 0;
	cin >> num;
	queue<int> cua;

	while (num >= -1001 and num < 1001) {
		if (num == -1001) {
			if (not cua.empty()) {
				int a = cua.front();
				cua.pop();
				if (min == a or max == a) Recalcular(cua, min, max);
				--elements;
				suma -= a;
			}
		}
		else {
			if (num < min) min = num;
			if (num > max) max = num;
			++elements;
			suma += num;
			cua.push(num);
		}
		if (cua.empty()) cout << 0 << endl;
		else cout << "min " << min << "; max " << max << "; media " << suma/elements << endl;
		cin >> num;
	}
}