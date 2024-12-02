#include <iostream>
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

	int inventory, time;
	int minTime = INT_MAX, bestHigh = 0;
	for (int targetHeight = 0; targetHeight <= 256; targetHeight++) {
		time = 0;
		inventory = b;

		for(const auto& [height, freq] : frequency) {
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