#include <iostream>
#include <string>

using namespace std;

int main() {
	long long prod = 1;
	for (long long i = 21; i <= 40; i++) {
		prod *= i;
	}
	cout << prod << endl;
}
