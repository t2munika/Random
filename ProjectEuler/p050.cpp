#include <iostream>

using namespace std;

int primes[1000000];

bool isPrime(int num, int numPrimes) {
	for (int i = 0; i < numPrimes; i++) {
		if ( num % primes[i] == 0 ) {
			return false;
		}
	}
	return true;
}

int main() {
	int numPrimes = 1;
	int num = 3;
	primes[0] = 2;
	int longest = 0;

	while ( num < 1000000 ) {
		if (isPrime(num, numPrimes)) {
			primes[numPrimes] = num;
			numPrimes++;
		}
		num++;
	}

	cout << "Done computing primes" << endl;

	for (int n = 0; n < numPrimes; n++) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			int j = i;
			while (sum < primes[n]) {
				sum += primes[j];		
				j++;
			}

			if (sum == primes[n] && j - i + 1 > longest) {
				longest = j - i + 1;
				cout << primes[n] << " " << longest << endl;
			}
		}
	}
}
