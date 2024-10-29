#include <iostream>
#include <vector>

using namespace std;

char board[51][51];
int n, m, min_color = 64;

void checkMin(char color, int y, int x) {
	int cnt = 0;

	for (int i = y; i < y + 8; i++) {
		for (int j = x; j < x + 8; j++) {
			if ((i + j) % 2 == 0) {
				if (board[i][j] != color) cnt++;
			}
			else {
				if (board[i][j] == color) cnt++;
			}
		}
	}
	if (min_color > cnt) min_color = cnt;
}

int main(void) {
	int min = 64;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			checkMin('W', i, j);
			checkMin('B', i, j);
		}
	}
	cout << min_color;

	return (0);
}