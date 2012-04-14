#include <iostream>

using namespace std;

int sumSquareDigits(int num) {
	int sum = 0;
	while (num > 0) {
		sum += ((num % 10) * (num % 10));
		num /= 10;
	}
	return sum;
}

int main() {
	int numStarts = 0;

	for (int i = 1; i < 10000000; i++) {
		int num = i;
		//cout << num;
		while (true) {
			num = sumSquareDigits(num);
			//cout << " " << num;
			if (num == 1) break;
			if (num == 89) {
				numStarts++;
				break;
			}
		}
		//cout << endl;
	}

	cout << "numStarts: " << numStarts << endl;
}
