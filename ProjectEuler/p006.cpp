#include <iostream>

using namespace std;

int main() {
	int sumsquares = 0;
	int squaresum = 0;

	for (int i = 1; i <= 100; i++) {
		sumsquares += i*i;
		squaresum += i;
	}
	squaresum *= squaresum;
	int diff = squaresum - sumsquares;
	cout << diff << endl;
}
