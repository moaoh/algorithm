#include <iostream>
#include <string>

using namespace std;

int num[5001];

int main(void)
{
	int n, k, sum, last;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
		num[i] = i;
	sum = k;
	cout << "<";
	while(num[sum])
	{
		if (num[sum])
		{
			if (sum + k > n) last = sum + k - n;
			else last = sum + k;
			cout << sum;
			if (num[last])
				cout << ", ";
			num[sum] = 0;
		}
		if (sum + k > n)
			sum = sum + k - n;
		else
			sum += k;
	}
	cout << ">";
	
	return (0);
}
