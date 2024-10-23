#include <iostream>
#include <map>

using namespace std;


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	map<int, int> number;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		number[k]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		if (number[k] != 0) cout << 1;
		else cout << 0;
		cout << "\n";
	}

	return (0);
}