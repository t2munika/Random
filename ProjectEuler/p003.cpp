#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long long primes[200000000];

bool isPrime(long long num, int numprimes) {
	for(int i = 0; i < numprimes; i++) {
		if (num % primes[i] == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int numprimes = 1;
	primes[0] = 2;
	long long factor = 0;
	long long num = 600851475143.0;

	for (double i = 3; i < num; i++) {
		if (isPrime((long long)i, numprimes)) {
			primes[numprimes] = i;
			numprimes++;
			if (fmod(num, i) == 0) {
				cout << setprecision(12) << i << endl;
				factor = i;
			}
		}
	}
}

