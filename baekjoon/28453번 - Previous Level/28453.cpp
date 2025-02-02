#include <iostream>

using namespace std;

int previousLevel(int level) {
	if (level >= 300) {
		return 1;
	}
	else if (level >= 275) {
		return 2;
	}
	else if (level >= 250) {
		return 3;
	}
	return 4;
}

int main() {

	int n, m;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout << previousLevel(m) << " ";
	}

	return 0;
}