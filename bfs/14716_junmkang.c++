// 현수막
#include <iostream>
#include <queue>

using namespace std;

int		map[251][251];

void	map_chk(int i, int j, int m, int n)
{
	int	nx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
	int	ny[8] = {1, 0, -1, 0, 1, -1, -1, 1};
	
	queue<pair<int, int> > q;
	map[i][j] = 0;
	q.push({i, j});
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 8; k++)
		{
			int y = temp.first +  ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || x < 0 || y >= m || x >= n) continue;
			if (map[y][x] != 1) continue;
			map[y][x] = 0;
			q.push({y, x});
		}
	}
}

int		main(void)
{
	int m, n;
	int y, x, count;

	cin >> m >> n;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	count = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				map_chk(i, j, m, n);
				count++;
			}
		}
	}
	cout << count;

	return (0);
}