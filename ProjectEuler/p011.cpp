#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int grid[20][20];

int main() {
	long long max = 0;

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cin >> grid[i][j];
		}
	}

	//check columns
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 20; j++) {
			long long prod = (long long) grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
			if (prod > max) {
				max = prod;
			}
		}
	}

	//check rows
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 16; j++) {
			long long prod = (long long) grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
			if (prod > max) {
				max = prod;
			}
		}
	}

	//check left diagonals
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			long long prod = (long long) grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
			if (prod > max) {
				max = prod;
			}
		}
	}

	//check right diagonals
	for (int i = 0; i < 16; i++) {
		for (int j = 3; j < 20; j++) {
			long long prod = (long long) grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3];
			if (prod > max) {
				max = prod;
			}
		}
	}

	cout << max << endl;
}
