#include <iostream>
#include <string>

int main(void) {

	std::string num;

	std::cin >> num;
	int len = num.length();

	if (num[0] > num[1] || num[len - 1] > num[len - 2]) {
		std::cout << "NON ALPSOO";
		return 0;
	}
	else {
		for (int i = 1; i < num.length(); i++) {
			if (num[i] == num[i - 1]) {
				std::cout << "NON ALPSOO";
				return 0;
			}
		}
		for (int i = 2; i < num.length(); i++) {
			int x, y;
			x = num[i] - num[i - 1];
			y = num[i - 1] - num[i - 2];
			if (x * y > 0 && x != y) {
				std::cout << "NON ALPSOO";
				return 0;
			}
		}
	}
	std::cout << "ALPSOO";
	return 0;
}