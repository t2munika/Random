#include <string>
#include <iostream>

using namespace std;

string double_string(string s) {
	int carry = 0;
	string result = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		int digit = (int) s[i] - 0x30;
		int prod = digit * 2 + carry;
		carry = prod / 10;
		char d = (char) (prod % 10) + 0x30;
		result.insert(0, 1, d);
	}
	if ( carry > 0 ) {
		result = "1" + result;
	}
	return result;
}

int main() {
	string num = "1";
	unsigned int sum = 0;
	for (int i = 0; i < 1000; i++) {
		num = double_string(num);
	}
	
	for (int i = 0; i < num.length(); i++) {
		sum += (num[i] - 0x30);
	}
	
	cout << "The Sum of " << num << " is " << sum << endl;	
}
