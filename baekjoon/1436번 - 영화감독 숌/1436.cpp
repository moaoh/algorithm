#include <iostream>

int main() {

	int n;
	int count = 0;
	int num = 666;

	std::cin >> n;
	while (1) {
		int copy = num;
		int six_count = 0;
		while (0 < copy) {
			if (copy % 10 == 6) six_count++;
			else six_count = 0;
			if (six_count == 3) {
				count++;
				break;
			}
			copy /= 10;
		}
		if (count == n) {
			std::cout << num << "\n";
			return 0;
		}
		num++;
	}
}