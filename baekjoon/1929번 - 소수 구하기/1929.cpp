#include <iostream>
#define max 1000000

using namespace std;

int a[1000001];

void f() {
	for(int i = 2; i <= max; i++) {
		a[i] = i;
	}
	for(int i = 2; i <= max; i++) {
		if(a[i] == 0) continue;
		for(int j = i+i; j <= max; j+=i) {
			a[j] = 0;
		}
	}
}

int main() {

	int m, n;
	cin >> m >> n;

	f();
	for (int i = m; i <= n; i++) {
		if (a[i] != 0) {
			cout << i << "\n";
		}
	}

	return 0;
}