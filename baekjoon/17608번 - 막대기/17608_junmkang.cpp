#include <iostream>
#include <stack>

using namespace std;

int		main(void)
{
	int		n, tmp, max, count;
	string	str;
	stack<int> s;
	
	cin >> n;
	count = 0;
	max = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		s.push(tmp);
	}
	for(int i = 0; i < n; i++)
	{
		tmp = s.top();
		s.pop();
		if (tmp > max)
		{
			max = tmp;
			count++;
		}
	}
	cout << count;
}
