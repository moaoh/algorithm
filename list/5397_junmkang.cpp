#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int		main(void)
{
	int		n;
	string		s;
	
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		list<char> lst;
		lst.clear();
		auto num = lst.end();
		for(int j = 0; j < s.length(); j++)
		{
			if (s[j] == '<')
			{
				if (num != lst.begin())
					num--;
			}
			(s[j] == '>')
			{
				if (num != lst.end())
					num++;
			}
			else if (s[j] == '-')
			{
				if (num != lst.begin())
					num = lst.erase(--num);
			}
			else
				lst.insert(num , s[j]);
		}
		for(auto j = lst.begin(); j != lst.end(); j++)
			cout << *j;
		cout << "\n";
	}

	return (0);
}
