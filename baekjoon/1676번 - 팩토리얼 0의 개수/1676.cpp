#include <iostream>

using namespace std;

int countTrailingZeros(int n) {
	int count = 0;
	for (int i = 5; n / i >= 1; i *= 5) {
		count += n / i;
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << countTrailingZeros(n) << endl;
	return 0;
}