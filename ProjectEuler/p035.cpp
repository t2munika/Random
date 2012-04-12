#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

long long primes[1000000];

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
	map<int, bool> primeMap;
	int circular = 0;

	for (double i = 3; i < 1000000; i++) {
		if (isPrime((long long)i, numprimes)) {
			primes[numprimes] = i;
			primeMap[i] = true;
			numprimes++;
		}
	}

	for (int i = 0; i < numprimes; i++) {
		if ( primes[i] < 10 ) {
			circular++;
		} else if (primes[i] < 100) {
			int circ = primes[i] / 10;
			circ = (primes[i] % 10) * 10 + circ;
			if (primeMap.count(circ) > 0 && primeMap.count(primes[i]) > 0) {
				circular++;
			}
		} else if (primes[i] < 1000) {
			int circ = primes[i] / 10;
			circ = (primes[i] % 10) * 100 + circ;
			int circ2 = circ / 10;
			circ2 = (circ % 10) * 100 + circ2;
			if (primeMap.count(circ2) > 0 && primeMap.count(circ) > 0 && 
				primeMap.count(primes[i]) > 0) {
				circular++;
			}
		} else if (primes[i] < 10000) {
			int circ = primes[i] / 10;
			circ = (primes[i] % 10) * 1000 + circ;
			int circ2 = circ / 10;
			circ2 = (circ % 10) * 1000 + circ2;
			int circ3 = circ2 / 10;
			circ3 = (circ2 % 10) * 1000 + circ3;
			if (primeMap.count(circ2) > 0 && primeMap.count(circ) > 0 && 
				primeMap.count(circ3) > 0 && primeMap.count(primes[i]) > 0) {
				circular++;
			}
		} else if (primes[i] < 100000) {
			int circ = primes[i] / 10;
			circ = (primes[i] % 10) * 10000 + circ;
			int circ2 = circ / 10;
			circ2 = (circ % 10) * 10000 + circ2;
			int circ3 = circ2 / 10;
			circ3 = (circ2 % 10) * 10000 + circ3;
			int circ4 = circ3 / 10;
			circ4 = (circ3 % 10) * 10000 + circ4;
			if (primeMap.count(circ2) > 0 && primeMap.count(circ) > 0 && 
				primeMap.count(circ3) > 0 && primeMap.count(primes[i]) > 0 && 
				primeMap.count(circ4) > 0) {
				circular++;
			}
		} else if (primes[i] < 1000000) {
			int circ = primes[i] / 10;
			circ = (primes[i] % 10) * 100000 + circ;
			int circ2 = circ / 10;
			circ2 = (circ % 10) * 100000 + circ2;
			int circ3 = circ2 / 10;
			circ3 = (circ2 % 10) * 100000 + circ3;
			int circ4 = circ3 / 10;
			circ4 = (circ3 % 10) * 100000 + circ4;
			int circ5 = circ4 / 10;
			circ5 = (circ4 % 10) * 100000 + circ5;
			if (primeMap.count(circ2) > 0 && primeMap.count(circ) > 0 && 
				primeMap.count(circ3) > 0 && primeMap.count(primes[i]) > 0 && 
				primeMap.count(circ4) > 0 && primeMap.count(circ5) > 0) {
				circular++;
			}
		} else {
			break;
		}
	}

	cout << "There are " << circular << " circular primes below 1000000." << endl;
}

