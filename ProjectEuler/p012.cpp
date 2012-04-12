#include <iostream>
#include <string>

using namespace std;

int numDivisors(long long n) {
	int num = 1;
	for (long long i = 2; i <= n; i++) {
		if ( n % i == 0 ) {
			num++;
		}
	}
	return num;
}

int main() {
	long long count = 3;
	long long num = 3;
	int divs;
	bool ex[4] = {false, false, false, false};

	while(true) {
		divs = numDivisors(num);
		if (divs > 500) {
			break;
		} else if (divs > 400 && !ex[3]) {
			cout << num << " has over 400 divisors." << endl;
			cout << "count = " << count << endl;
			ex[3] = true;
		} else if (divs > 300 && !ex[2]) {
			cout << num << " has over 300 divisors." << endl;
			cout << "count = " << count << endl;
			ex[2] = true;
		} else if (divs > 200 && !ex[1]) {
			cout << num << " has over 200 divisors." << endl;
			cout << "count = " << count << endl;
			ex[1] = true;
		} else if (divs > 100 && !ex[0]) {
			cout << num << " has over 100 divisors." << endl;
			cout << "count = " << count << endl;
			ex[0] = true;
		} else {}
		num += count;
		count++;
	}
	cout << num << endl;
	cout << "Sum of numbers 1 to " << count-1 << " has " << divs << " divisors." << endl;

}
