#include <iostream>
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int d(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if ( num % i == 0 ) {
			sum += i;
		}
	}
	return sum;
}

int main() {
	int abundant[28123];
	int sums[28123];
	int n = 0;
	int numSums = 0;

	// find abundant numbers
	for (int i = 1; i <= 35; i++) {
		int s = d(i);
		if ( s > i ) {
			abundant[n] = i;
			n++;
			cout << i << endl;
		}
	}
	// compute sums
	cout << "SUMS" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = abundant[i] + abundant[j];
			if ( sum > 35 ) {
				continue;
			} else {
				sums[numSums] = sum;
				numSums++;
			}
		}
	}
	sums[numSums] = 35;
	numSums++;

	// sort sums
	qsort(sums,numSums,sizeof(int),compare);

	for (int i = 0; i < numSums; i++) {
		cout << sums[i] << endl;
	}

	int start = 0;
	int total = 0;
//	cout << "Calculate total:" << endl;
	for (int i = 0; i < numSums; i++) {
//		cout << total << " " << start+1 << " " << sums[i] << endl;
		for(int j = start+1; j < sums[i]; j++) {
			total += j;
		}
		start = sums[i];
//		cout << total << endl;
	}
	cout << "numSums = " << numSums << ", n = " << n << ", total = " << total << endl;	
}
