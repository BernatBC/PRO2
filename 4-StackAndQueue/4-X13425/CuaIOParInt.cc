#include "CuaIOParInt.hh"

void llegirCuaParInt(queue<ParInt>& c) {
	ParInt a;
	bool b = a.llegir();
	while (b) {
		c.push(a);
		b = a.llegir();
	}
}

void escriureCuaParInt(queue<ParInt> c) {
	while (not c.empty()) {
		ParInt a = c.front();
		a.escriure();
		c.pop();
	}
}