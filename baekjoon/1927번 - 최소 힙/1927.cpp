#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, n;
	std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;

	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> n;
		if (n == 0) {
			if (minHeap.empty()) cout << '0' << "\n";
			else {
				cout << minHeap.top() << "\n";
				minHeap.pop();
			}
		}
		else minHeap.push(n);
	}

	return 0;
}