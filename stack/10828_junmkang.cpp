#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(void)
{
	int n, tmp;
	string str;
	stack<int> s;
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> tmp;
			s.push(tmp);
		}
		else if (str == "pop")
		{
			if (s.size() <= 0) cout << "-1" << "\n";
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size")
			cout << s.size() << "\n";
		else if (str == "empty")
		{
			if (s.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (str == "top")
		{
			if (s.size() <= 0) cout << "-1" << "\n";
			else cout << s.top() << "\n";
		}
	}
	
	return (0);
}
