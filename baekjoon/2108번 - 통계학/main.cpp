#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int findMostFrequent(const vector<int>& vec) {
	map<int, int> m;

	for(int num : vec) {
		m[num]++;
	}
	int maxFrequent = 0;
	for(const auto& [num, count] : m) {
		maxFrequent = max(maxFrequent, count);
	}
	vector<int> mostFrequent;
	for(const auto& [num, count] : m) {
		if (maxFrequent == count) {
			mostFrequent.push_back(num);
		}
	}
	sort(mostFrequent.begin(), mostFrequent.end());
	if (mostFrequent.size() >= 2) {
		return mostFrequent[1];
	}
	return mostFrequent[0];
}

int range(const vector<int>& vec) {
	int maxVal = *std::max_element(vec.begin(), vec.end());
	int minVal = *std::min_element(vec.begin(), vec.end());

	return maxVal - minVal;
}

int main() {
	int n, x;
	vector<int> vec;
	double sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		vec.push_back(x);
		sum += x;
	}
	sort(vec.begin(), vec.end());

	cout << static_cast<int>(round(sum / n)) << endl;	// 평균값 반올림
	cout << vec[n / 2] << endl;							// 중앙값
	cout << findMostFrequent(vec) << endl;				// 최빈값
	cout << range(vec) << endl;							// 범위

	return 0;
}