#include <iostream>

using namespace std;

int main() {
	int a;
	int b;
	int c;

	for(a = 1; a <= 1000; a++) {
		for (b = a+1; b <= 1000; b++) {
			c = 1000 - a - b;
			if ( a*a + b*b == c*c ) goto end;
		}
	}
end:
	int product = a * b * c;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << product << endl;

	return 0;
}
		
