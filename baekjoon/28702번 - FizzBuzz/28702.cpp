#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool isNumeric(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

string fizzBuzz(int answer) {
	if (answer % 3 == 0 && answer % 5 == 0) return "FizzBuzz";
	else if (answer % 3 == 0) return "Fizz";
	else if (answer % 5 == 0) return "Buzz";
	return to_string(answer);
}

int main(void) {

	vector<string> v;
	string x;
	int answer;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		v.push_back(x);
	}
	for (size_t i = 0; i < v.size(); i++) {
		if (isNumeric(v[i])) {
			answer = stoi(v[i]);
			answer += v.size() - i;
			cout << fizzBuzz(answer);
			break;
		}
	}

	return (0);
}