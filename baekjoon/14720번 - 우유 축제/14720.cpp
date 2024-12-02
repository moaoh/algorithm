#include <iostream>

using namespace std;

int main() {

	int n, m, last = 2, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (last == 2 && m == 0) {
			last = 0;
			count++;
		}
		if (last == 0 && m == 1) {
			last = 1;
			count++;
		}
		if (last == 1 && m == 2) {
			last = 2;
			count++;
		}
	}
	cout << count;

	return 0;
}