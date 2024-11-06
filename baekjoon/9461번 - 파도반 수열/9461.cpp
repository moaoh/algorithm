#include <iostream>

using namespace std;

long long arr[101];

long long number(long long n) {
	if (n == 1) return 1;
	else if (n == 2) return 1;
	else if (n == 3) return 1;
	else if (n == 4) return 2;
	else if (arr[n] != 0) return arr[n];
	else return arr[n] = number(n - 2) + number(n - 3);
}

int main() {

	long long t, n;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << number(n) << "\n";
	}

	return 0;
}