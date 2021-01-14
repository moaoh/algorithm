#include <iostream>
#include <string>
#include <stack>

using namespace std;

int		main(void)
{	
	while(1)
	{
		string str;
		getline(cin, str);
		if (str == ".")
			break;
		stack<char> s;
		int chk = 0;
		for(int i = 0; i < str.size(); i++)
		{
			if (str[i] == '(' || str[i] == '[')
				s.push(str[i]);
			if (str[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
					s.pop();
				else 
				{
					chk++;
					break;
				}
			}
			if (str[i] == ']')
			{
				if (!s.empty() && s.top() == '[')
					s.pop();
				else 
				{
					chk++;
					break;
				}
			}
		}
		if (!s.empty() || chk != 0)
			cout << "no" << "\n";
		else
			cout << "yes" << "\n";
	}
	
	return (0);
}
