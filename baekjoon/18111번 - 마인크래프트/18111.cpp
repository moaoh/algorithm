#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

	int n, m, b, land;

	cin >> n >> m >> b;

	unordered_map<int, int> frequency;
	for (int i = 0; i < n * m; i++) {
		cin >> land;
		frequency[land]++;
	}

	vector<pair<int, int> > freqList;
	for (const auto& [land, freq] : frequency) {
		freqList.emplace_back(land, freq);
	}

	std::sort(freqList.begin(), freqList.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		return a.first < b.first;
	});

	int inventory, time;
	int minTime = INT_MAX, bestHigh = 0;
	for (int targetHeight = 0; targetHeight <= 256; targetHeight++) {
		time = 0;
		inventory = b;

		for(const auto& [height, freq] : freqList) {
			if (height < targetHeight) {
				int blocksNeeded = (targetHeight - height) * freq;
				inventory -= blocksNeeded;
				time += blocksNeeded;
			} else if (height > targetHeight) {
				int blocksRemoved = (height - targetHeight) * freq;
				inventory += blocksRemoved;
				time += blocksRemoved * 2;
			}
		}

		if (0 <= inventory) {
			if (minTime > time || (minTime == time && bestHigh < targetHeight)) {
				minTime = time;
				bestHigh = targetHeight;
			}
		}
	}
	cout << minTime << " " << bestHigh;

	return 0;
}