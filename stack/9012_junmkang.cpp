#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int		main(void)
{
	int n, chk;
	char c;
	string str;
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		chk = 0;
		stack<char> s;
		for(int j = 0; j < str.size(); j++)
		{
			if (str[j] == '(')
			{
				s.push('(');
			}
			else if (str[j] == ')' && s.size() > 0)
			{
				c = s.top();
				s.pop();
				if (c != '(')
					chk++;
			}
			else
			{
				chk++;
				break;
			}
		}
		int size = 0;
		size = s.size();
		if (chk == 0 && size == 0) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		
	}
	
	return (0);
}
