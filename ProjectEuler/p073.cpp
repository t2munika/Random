#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a <= 0) {
		return b;
	} else if (b <= 0) {
		return a;
	} else {
		if (a > b) {
			return gcd(a-b, b);
		} else {
			return gcd(a, b-a);
		}
	}
}

int main() {
	int numFracs = 0;

//	cout << gcd(11, 22) << endl;
//	cout << gcd(46, 69) << endl;
//	cout << gcd(43, 89) << endl;

	for (int i = 1; i <= 12000; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(j, i) > 1 || i % j == 0) {
				continue;
			}
			if (i / j == 2) {
				//cout << j << "/" << i << endl;
				numFracs++;
			}
		}
	}

	cout << numFracs << endl;
}
