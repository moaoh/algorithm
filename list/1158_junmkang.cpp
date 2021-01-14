#include <iostream>
#include <string>
#include <list>

using namespace std;

int		main(void)
{
	int		n;
	int		k;
	cin >> n >> k;
	list<int> l;
	for(int i = 1; i <= n; i++)
		l.push_back(i);
	list<int>::iterator num;
	num = l.begin();
	cout << "<";
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < k; j++)
		{
			++num;
			if (num == l.end())
				num = l.begin();
		}
		if (i == n) cout << *num;
		else cout << *num << ", ";
		num = l.erase(num);
		if (num == l.end())
		num = l.begin();
	}
	cout << ">";
	return (0);
}
