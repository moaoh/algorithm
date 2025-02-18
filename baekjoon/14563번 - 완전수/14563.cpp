#include <iostream>

using namespace std;

int main() {

	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		int sum = 0;
		for (int j = 1; j <= num / 2; j++) {
			if (num % j == 0) {
				sum += j;
			}
		}
		if (sum == num) cout << "Perfect" << endl;
		else if (sum < num) cout << "Deficient" << endl;
		else cout << "Abundant" << endl;
	}

	return 0;
}