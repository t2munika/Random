#include <iostream>

using namespace std;

int main() { 
	int lessthan = 0;
	int equal = 0;
	int greaterthan = 0;

	for (int i = 10; i <= 90000; i++) {
		long long sum = 0;
		long long num = i; 
		while (num > 0) {
			sum += (num % 10) * (num % 10) * (num % 10) * (num % 10);
			num /= 10;
		}
		if (sum < i) {
			cout << i << " LESSTHAN" << endl;
			lessthan++;
		} else if (sum == i) {
			cout << i << " EQUAL" << endl;
			equal++;
		} else {
			cout << i << " GREATERTHAN" << endl;
			greaterthan++;
		}
	}
	cout << endl;
	cout << lessthan << " Numbers with sums less than the number itself." << endl;
	cout << equal << " Numbers with sums equal the number itself." << endl;
	cout << greaterthan << " Numbers with sums greater than the number itself." << endl;
}
