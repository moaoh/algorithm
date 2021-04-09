#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[102][102];

void size_map(int i, int j, int n, int m, int *count)
{
	int nx[4] = {0, 1, 0, -1};
	int ny[4] = {1, 0, -1, 0};

	queue<pair<int, int> > q;
	q.push({i, j});
	map[i][j] = 0;
	(*count)++;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int r = temp.first + ny[k];
			int c = temp.second + nx[k];
			if (r < 1 || r > n || c < 1 || c > m) continue;
			if (map[r][c] != 1) continue;
			map[r][c] = 0;
			q.push({r, c});
			(*count)++;
		}
	}
}

int	chk_map(int n, int m)
{
	int count, max;

	max = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if (map[i][j] == 1)
			{
				count = 0;
				size_map(i, j, n, m, &count);
			}
			if (count > max)
				max = count;
		}
	}
	return (max);
}

int main(void)
{
	int n, m, k;
	int r, c, max;

	cin >> n >> m >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> r >> c;
		map[r][c] = 1;
	}
	max = chk_map(n, m);
	cout << max;

	return (0);
}