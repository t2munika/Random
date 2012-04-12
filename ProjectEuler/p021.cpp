#include <iostream>

using namespace std;

int d(int num) {
	int sum = 0;
	for(int i = 1; i < num; i++) {
		if ( num % i == 0) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int amicable[10000];
	int total = 0;

	amicable[0] = -1;
	for (int i = 1; i <= 10000; i++) {
		amicable[i] = d(i);		
	}

	total = 0;
	for (int i = 0; i < 10000; i++) {
		if (amicable[i] < 0 || amicable[i] > 9999) {
			continue;
		}
		if ( amicable[ amicable[i] ] == i && amicable[i] != i) {
			cout << total << endl;
			total = total + i + amicable[i];
			cout << i << " " << amicable[i] << " " << total << endl;
			amicable[ amicable[i] ] = -1;
			amicable[i] = -1;
		}
	}

	cout << "Sum of amicable numbers is " << total << endl;
}
