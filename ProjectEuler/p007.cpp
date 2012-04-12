#include <iostream>

using namespace std;

int primes[10001];

bool isPrime(int num, int numprimes) {
	for(int i = 0; i < numprimes; i++) {
		if (num % primes[i] == 0) {
			return false;
		}
	}
/*
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
*/
	return true;
}

int main() {
	int numprimes = 1;
	primes[0] = 2;
	long i = 3;

	while(numprimes <= 10001) {
		if (isPrime(i, numprimes)) {
			primes[numprimes] = i;
			numprimes++;
		}
		i++;
	}
	cout << "Number of primes: " << numprimes << endl;
	for (int i = 0; i < numprimes; i++) {
		cout << primes[i] << endl;
	}
}
