#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> pokemon(n + 1);
	unordered_map<string, int> pokemonList;

	for (int i = 1; i <= n; i++) {
		cin >> pokemon[i];
		pokemonList[pokemon[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (isdigit(s[0])) {
			int pos = stoi(s);
			cout << pokemon[pos] << '\n';
		} else {
			cout << pokemonList[s] << '\n';
		}
	}

	return 0;
}