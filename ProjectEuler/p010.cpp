#include <iostream>

using namespace std;

long long primes[2000000];

bool isPrime(int num, int numprimes) {

	for(int i = 0; i < numprimes; i++) {
		if (num % primes[i] == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	long long sum = 0;
	int numprimes = 1;
	primes[0] = 2;

	cout << "1st prime: 2" << endl;
	for(int i = 3; i < 2000000; i++) {
		if (isPrime(i, numprimes)) {
			primes[numprimes] = i;
			numprimes++;
			cout << numprimes << "th prime: " << primes[numprimes-1] << endl;
		}
	}

	cout << "Number of primes: " << numprimes << endl;

	for (int i = 0; i < numprimes; i++) {
		sum += primes[i];
	}
	cout << sum << endl;
}
