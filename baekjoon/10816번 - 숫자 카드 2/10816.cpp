#include <iostream>
#include <map>

using namespace std;


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	map<int, int> card;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		card[k]++;
	}
	cin >> m;
	for (int j =0; j < m; j++) {
		cin >> k;
		cout << card[k] << " ";
	}

	return (0);
}