#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
	int numletters = 0;
	for( int i = 1; i < 1000; i++ ) {
		int total = 0;
		if (i >= 100) {
			total += 7; // for word hundred
			switch ( i / 100) {
				case 1:
				case 2:
				case 6:
					total += 3;
					break;
				case 3:
				case 7:
				case 8:
					total += 5;
					break;
				case 4:
				case 5:
				case 9:
					total += 4;
					break;
				default: 
					cout << "error! i/100 = " << i/100 << endl;
					break;
			}
			if ( i % 100 != 0 ) {
				total += 3; // add the "and"
			} else {
				numletters += total;
				cout << i << " has " << total << " letters." << endl;
				continue;
			}		
		}
		
		switch (i % 100) {
			case 10:
				total += 3;
				break;
			case 11:
			case 12:
				total += 6;
				break;
			case 13:
			case 14:
			case 18:
			case 19:
				total += 8;
				break;
			case 15:
			case 16:
				total += 7;
				break;
			case 17:
				total += 9;
				break;
			default:
				assert( i % 100 < 10 || i % 100 > 19 );
		}

		if ( (i % 100) / 10 == 1 ) { 	
			numletters += total;	
			cout << i << " has " << total << " letters." << endl;
			continue; 
		}

		switch ( (i % 100) / 10 ) {
			case 2:
			case 3:
			case 8:
			case 9:
				total += 6;
				break;
			case 4:
			case 5:
			case 6:
				total += 5;
				break;
			case 7:
				total += 7;
				break;
			default:
				assert( i % 100 < 10 );
		}

		switch ( i % 10 ) {
			case 0: 
				break;
			case 1:
			case 2:
			case 6:
				total += 3;
				break;
			case 3:
			case 7:
			case 8:
				total += 5;
				break;
			case 4:
			case 5:
			case 9:
				total += 4;
				break;
			default: 
				cout << "error! i = " << i << endl;
				break;
		}
		numletters += total;
		cout << i << " has " << total << " letters." << endl;
	}

	numletters += 11;
	cout << "1000 has 11 letters." << endl;
	cout << numletters << endl;
}
