#include <iostream>
#include <string>

using namespace std;

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

bool isPalindrome(string str) {
	int i = 0;
	int j = str.length()-1;

	while ( i < j ) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

int main() {
	int max = 0;

	for (int i = 100; i < 1000; i++) {
		for(int j = 100; j < 1000; j++) {
			int prod = i * j;
			//cout << i << " * " << j << " = ";
			string str = intToString(prod);
			//cout << str << " = " << prod << endl;
			if (isPalindrome(str)) {
				if ( prod > max ) {
					max = prod;
				}
			}		
		}
	}
	cout << max << endl;
}
