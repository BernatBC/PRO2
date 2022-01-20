#include "ParInt.hh"
#include "CuaIOParInt.hh"

int main() {
	int t1 = 0;
	int t2 = 0;
	queue<ParInt> c;
	queue<ParInt> c1;
	queue<ParInt> c2;
	llegirCuaParInt(c);
	while (not c.empty()) {
		ParInt a = c.front();
		if (t2 < t1) {
			c2.push(a);
			t2 += a.segon();
		}
		else {
			c1.push(a);
			t1 += a.segon();
		}
		c.pop();
	}
	escriureCuaParInt(c1);
	cout << endl;
	escriureCuaParInt(c2);
}