#include <iostream>
#include <vector>

using namespace std;

int paper[129][129];

void findPaper(int y, int x, int n, int &blue, int &white) {
	int firstColor = paper[y][x];
	bool elseColorCheck = true;
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (firstColor != paper[i][j]) {
				elseColorCheck = false;
				break;
			}
		}
	}
	if (elseColorCheck == false) {
		int nHalf = n / 2;
		findPaper(y, x, nHalf, blue, white);
		findPaper(y, x + nHalf, nHalf, blue, white);
		findPaper(y + nHalf, x, nHalf, blue, white);
		findPaper(y + nHalf, x + nHalf, nHalf, blue, white);
	} 
	else {
		if (firstColor == 1) {
			blue++;
		}
		else {
			white++;
		}
	}
}

int main() {

	int n;
	int blue = 0, white = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	findPaper(0, 0, n, blue, white);
	cout << white << "\n" << blue << endl;

	return 0;
}