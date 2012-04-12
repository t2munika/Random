#include <iostream>
#include <string>

using namespace std;

string largenums[100];

string intToString(int num) {
	string str = "";
	int n = num;
	while( num > 0 ) {
		char c = (num % 10) + 48;
		str.insert(0, 1, c);
		num /= 10;
	}
	return str;		
}

int main() {
	int carry = 0;
	int sum = 0;
	string result = "";

	for (int i = 0; i < 100; i++) {
		getline(cin, largenums[i]);
	}

	for (int j = 49; j >= 0; j--) {
		sum = carry;
		for (int i = 0; i < 100; i++) {
			int d = (int)largenums[i][j] - 48;
			sum += d; 
		}
		char c = (sum % 10) + 48;
		result.insert(0, 1, c);
		sum /= 10;
		carry = sum;		
	}

	cout << carry << result << endl;
}
		
