// 토마토
#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];
queue<pair<int, int> > q;

void		chk_map(int n, int m)
{
	int		count;
	int		ny[4] = {0, 1, 0, -1};
	int		nx[4] = {1, 0, -1, 0};

	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || y >= n || x < 0 || x >= m) continue;
			if (map[y][x] == -1 || map[y][x] > 0) continue;
			count = map[temp.first][temp.second] + 1;
			map[y][x] = count;
			q.push({y, x});
		}
	}
}

int main(void)
{
	int m, n;
	int max, num;

	cin >> m >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				q.push({i, j});
		}

	chk_map(n, m);

	max = 0;
	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (max < map[i][j])
				max = map[i][j];
			if (map[i][j] == 0)
			{
				cout << "-1";
				return (0);
			}
		}
	}

	cout << max - 1;

	return (0);
}