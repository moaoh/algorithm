#include <iostream>
​
using namespace std;
​
int queue[10001];
​
int main(void)
{
	int n, front, size, tmp;
	string	str;
	
	cin >> n;
	front = 0;
	size = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push")
		{
			cin >> tmp;
			queue[size] = tmp;
			size++;
		}
		else if (str == "pop")
		{
			if (front < size)
			{
				cout << queue[front] << "\n";
				front++;
			}
			else
				cout << "-1" << "\n";
		}
		else if (str == "size")
		{
			tmp = 0;
			for(int i = front; i < size; i++)
				if (queue[i] != 0)
					tmp++;
			cout << tmp << "\n";
		}
		else if (str == "empty")
		{
			if (front < size)
				cout << "0" << "\n";
			else
				cout << "1" << "\n";
		}
		else if (str == "front")
		{
			if (front >= size)
				cout << "-1" << "\n";
			else
			cout << queue[front] << "\n";
		}
		else if (str == "back")
		{
			if (front >= size)
				cout << "-1" << "\n";
			else
			cout << queue[size - 1] << "\n";
		}
	}
	
	return (0);
}
