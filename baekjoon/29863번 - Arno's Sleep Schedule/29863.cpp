#include <iostream>

using namespace std;

int main() {
	int b, f, total;

	cin >> b >> f;
	if (b > f) {
		total = 24 - b + f;
	}
	else {
		total = f - b;
	}
	cout << total;

	return 0;
}