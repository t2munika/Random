#include <iostream>
#include <string>

using namespace std;

int main() {
	int maxlength = 0;
	long long startnum = 1;
	for (int i = 1; i < 1000000; i++) {
		int len = 1;
		long long s = i;
		int start = i;
		do {
			if ( s % 2 == 0 ) {
				s /= 2;
			} else {
				s = 3*s + 1;
			}
			len++;
		} while( s > 1 );
		
		if (len > maxlength) {
			maxlength = len;
			startnum = start;
			cout << "New start number = " << startnum << endl;
			cout << "Length = " << maxlength << endl;
		}
	}
	cout << "Start number = " << startnum << endl;
	cout << "Length = " << maxlength << endl;
	cout << startnum;
	do {
		if ( startnum % 2 == 0 ) {
			startnum /= 2;
		} else {
			startnum = 3*startnum + 1;
		}
		cout << " -> " << startnum;
	} while( startnum > 1 );	
	cout << endl;
}
				
