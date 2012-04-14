#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= (int) sqrt((double)num); i++) {
		if ( num % i == 0 ) {
			return false;
		}
	}
	return true;
}

int main() {
	int num = 3;
	int count = 1000000;
	while(true) {
beg:	if (isPrime(num)) {
			num += 2;
			continue;
		}
		for (int i = 1; i < (int) sqrt((double)num); i++) {
			if ( isPrime(num - (2 * i * i)) ) {
				num += 2;
				if (num > count) {
					cout << "num is over " << count << endl;
					count += 1000000;
				}
				goto beg;
			}			
		}
		cout << num << endl;
		break;
	}
}
