#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, x;
	
	cin >> n;

	vector<int> answer(n);
	vector<char> output;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> answer[i];
	}

	int target = 0, nCount = 1;
	bool possible = true;
	for (int i = 0; i < n; i++) {
		target = answer[i];

		while (nCount <= target) {
			s.push(nCount++);
			output.push_back('+');
		}

		if (!s.empty() && s.top() == target) {
			s.pop();
			output.push_back('-');
		} else {
			possible = false;
			break;
		}
	}
	if (possible) {
		for (const auto& a : output) {
			cout << a << "\n";
		}
	}
	else cout << "NO" << "\n";

	return 0;
}