#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {

	vector<long long> v;
	long long low = 1, mid, high = 0;
	long long k, n, x;

	cin >> k >> n;
	for(int i = 0; i < k; i++) {
		cin >> x;
		v.push_back(x);
		high = max(high, x);
	}

	
	while (low <= high) {
		mid = (high + low) / 2;
		int count = 0;
		for(auto &a : v) {
			count += a / mid;
		}
		if (count >= n) low = mid + 1;
		else high = mid - 1;
	}
	
	cout << high;

	return 0;
}