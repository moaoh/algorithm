#include <iostream>
#include <set>

using namespace std;

set<int> s;
set<int> setAll = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

void add(int num) {
	s.insert(num);
}
void remove(int num) {
	s.erase(num);
}
void check(int num) {
	if (s.find(num) != s.end()) cout << 1 << "\n";
	else cout << 0 << "\n";
}
void toggle(int num) {
	if (s.find(num) != s.end()) s.erase(num);
	else s.insert(num);
}

void all() {
	s = setAll;
}
void empty() {
	s.clear();
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

	int m, num;
	string command;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> command;
		if (command == "empty" || command == "all") {
			if (command == "all") all();
			if (command == "empty") empty();
		}
		else {
			cin >> num;
			if (command == "add") add(num);
			if (command == "remove") remove(num);
			if (command == "check") check(num);
			if (command == "toggle") toggle(num);
		}
	}

	return (0);
}