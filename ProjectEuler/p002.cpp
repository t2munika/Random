#include <iostream>

using namespace std;

int main() {
	int first = 1;
	int second = 2;
	int sum = 2;

	while(true) {
		int next = first + second;

		if (next > 4000000) {
			break;
		}

		if (next % 2 == 0) {
			sum += next;
		}

		first = second;
		second = next;
	}

	cout << sum << endl;

	return 0;
}
