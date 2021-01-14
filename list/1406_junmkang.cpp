#include <iostream>
#include <list>
#include <string>
#include <cstdio>

using namespace std;

int		a[30];

int		main(void)
{
	string		s;
	int			n;
	char		m;
	char		temp;
	
	cin >> s;
	cin >> n;
	list<char> str(s.begin(), s.end());
	auto num = str.end();
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		if (m == 'L' && num != str.begin())
			num--;
		else if (m == 'D' && num != str.end())
			num++;
		else if (m == 'B' && num != str.begin())
			num = str.erase(--num);
		else if (m == 'P')
		{
			cin >> temp;
			str.insert(num, temp);
		}
	}
	for(auto i = str.begin(); i != str.end(); i++)
		cout << *i;
	
	return (0);
}
