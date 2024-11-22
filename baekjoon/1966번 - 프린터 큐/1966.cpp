#include <iostream>
#include <queue>

using namespace std;

int main() {

	int t, n, m, x;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		queue<int> que;
		priority_queue<int> pque;
		for (int j = 0; j < n; j++) {
			cin >> x;
			que.push(x);
			pque.push(x);
		}
		while (true) {
			if (que.front() == pque.top()) {
				if (m == 0) {
					cout << n - que.size() + 1 << endl;
					break;
				}
				else {
					que.pop();
					pque.pop();
				}
			}
			else {
				int temp = que.front();
				que.pop();
				que.push(temp);
			}
			m--;
			if (m < 0) {
				m = que.size() - 1;
			}
		}
	}

	return 0;
}