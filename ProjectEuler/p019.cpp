#include <iostream>

using namespace std;

int main() {
	int year[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
	int leap[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336 };

	bool leapYear = false;
	int currSunday = -1;
	int numSundays = 0;

	for (int currYear = 1901; currYear <= 2000; currYear++) {
		leapYear = ((currYear % 4 == 0 && currYear % 100 != 0) || (currYear % 400 == 0));
		int numDays = leapYear ? 366 : 365;

		while (currSunday < numDays) {
			for (int i = 0; i < 12; i++) {
				if (leapYear) {
					if ( currSunday < leap[i] ) break;
					if ( currSunday == leap[i] ) numSundays++;
				} else {
					if ( currSunday < year[i] ) break;
					if ( currSunday == year[i] ) numSundays++;
				}
			}
			currSunday += 7;
		}
		currSunday = currSunday - numDays;			
	}

	cout << numSundays << endl;
}
