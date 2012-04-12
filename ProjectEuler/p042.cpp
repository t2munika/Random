#include <iostream>
#include <string>
#include <map>

using namespace std;

string words[2000];
map<long long, int> triangle;

void genTriNums() {
	for(int i = 1; i < 500; i++) {
		long long tri = i * (i+1) / 2;
		triangle[tri] = i;
	}
}

int main() {
	string str;
	int numwords = 0;
	int triwords = 0;

	genTriNums();

	getline(cin, str, ',');
	do {
		words[numwords] = str.substr(1, str.length() - 2);
		numwords++;
		getline(cin, str, ',');
	} while(!cin.eof());

	for (int i = 0; i < numwords; i++) {
		int value = 0;
		for (int j = 0; j < words[i].length(); j++) {
			value += (int) words[i][j] - 64;
		}
		cout << words[i] << " = " << value << endl;
		if ( triangle.count(value) > 0 ) {
			triwords++;
			cout << value << " is the " << triangle[value] << "th triangle number" << endl;
		} 
	}

	cout << "Number of triangle words is " << triwords << endl;
}
