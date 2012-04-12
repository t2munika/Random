#include <map>
#include <iostream>

using namespace std;

int main() {
	map<long long, bool> triangle;
	map<long long, bool> pentagon;
	map<long long, bool> hexagon;
	long long count = 1;

	while(true) {
		long long tri = count * (count+1) / 2;
		long long pen = count * (3*count - 1) / 2;
		long long hex = count * (2*count - 1);
		triangle[tri] = true;
		pentagon[pen] = true;
		hexagon[hex] = true;

		if (triangle.count(tri) > 0 && pentagon.count(tri) > 0 && hexagon.count(tri) > 0) {
			cout << tri << " works." << endl;
			if (tri > 40755) { break; }
		}
		count++;
	}
}
