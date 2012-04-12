#include <iostream>
#include <string>
#include <set>

using namespace std;

int factorial(int n) {
	int prod = 1;
	if (n == 0) {
		return 1;
	} else {
		return n * factorial(n-1);
	}
}

int main() {
	set<int> digits;
	int dgts[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
	int digit
}
