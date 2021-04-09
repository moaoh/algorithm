#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int chk[100001];

int	location(int n, int k)
{
	queue<pair<int, int> > q;
	q.push({n, 0});
	while(!q.empty())
	{
		auto temp = q.front(); q.pop();
		if (temp.first == k) return (temp.second);
		if (temp.first + 1 <= 100000 && chk[temp.first + 1] == 0) {
			q.push({temp.first + 1, temp.second + 1});
			chk[temp.first + 1] = 1;
		}
		if (temp.first - 1 >= 0 && chk[temp.first - 1] == 0) {
			q.push({temp.first - 1, temp.second + 1});
			chk[temp.first - 1] = 1;
		}
		if (temp.first * 2 <= 100000 && chk[temp.first * 2] == 0) {
			q.push({temp.first * 2, temp.second + 1});
			chk[temp.first * 2] = 1;
		}
	}
	return (0);
}

int main(void)
{
	int n, k;

	cin >> n >> k;
	if (n == k) cout << 0;
	else cout << location(n, k);

	return (0);
}