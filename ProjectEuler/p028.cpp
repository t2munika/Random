#include <iostream>

using namespace std;

int main() {
	int sum = 1;
	int num = 1;

	for (int i = 2; i <=1001; i += 2) {
		for (int j = 0; j < 4; j++) {
			num += i;
			//cout << num << endl;
			sum += num;
		}
		
	}
	cout << sum << endl;
}
