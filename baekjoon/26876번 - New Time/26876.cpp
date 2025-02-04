#include <iostream>

using namespace std;

int main() {

	string beforeTime, afterTime;
	int beforeHour, beforeMin, afterHour, afterMin;

	cin >> beforeTime >> afterTime;
	beforeHour = stoi(beforeTime.substr(0, 2));
	beforeMin = stoi(beforeTime.substr(3, 5));
	afterHour = stoi(afterTime.substr(0, 2));
	afterMin = stoi(afterTime.substr(3, 5));

	int count = 0;
	if (beforeMin < afterMin) {
		count += afterMin - beforeMin;
	} else if (beforeMin > afterMin) {
		count += 60 - beforeMin;
		beforeMin = 0;
		count += afterMin - beforeMin;
		beforeHour++;
	}
	if (beforeHour < afterHour) {
		count += afterHour - beforeHour;
	}
	else if (beforeHour > afterHour) {
		count += 24 - beforeHour;
		beforeHour = 0;
		count += afterHour - beforeHour;
		beforeHour++;
	}
	cout << count;

	return 0;
}