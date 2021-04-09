#include <iostream>
#include <list>
#include <string>
#include <cstdio>

using namespace std;

int		main(void)
{
	string		s;
	int			n;
	int			num;
	char		m;
	char		temp;
	
	cin >> s;
	cin >> n;
	list<char> str(s.begin(),s.end());
	num = n;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		if (m == 'L' && num > 0)
			num--;
		else if (m == 'D' && num < n)
			num++;
		else if (m == 'B' && num > 0)
			str.erase(--num);
		else if (m == 'P')
		{
			cin >> temp;
			str.insert(num, temp);
		}
	}
	for(int i = str.begin(); i < str.end(); i++)
		cout << str[i];
	
	return (0);
}
