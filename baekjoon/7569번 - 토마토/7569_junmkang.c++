// 토마토
#include <iostream>
#include <queue>

using namespace std;

int map[101][101][101];
queue<pair<int, pair<int, int> > > q;

void	chk_map(int h, int n, int m)
{
	int count = 0;
	int nx[6] = {0, 1, 0, -1, 0, 0};
	int ny[6] = {1, 0, -1, 0, 0, 0};
	int nz[6] = {0, 0, 0, 0, 1, -1};


	while(!q.empty())
	{
		pair<int, pair<int, int> > temp = q.front();
		q.pop();
		for(int k = 0; k < 6; k++)
		{
			int z = temp.first + nz[k];
			int y = temp.second.first + ny[k];
			int x = temp.second.second + nx[k];
			if (z < 0 || y < 0 || x < 0 || z >= h || y >= n || x >= m) continue;
			if (map[z][y][x] == -1 || map[z][y][x] > 0) continue;
			count = map[temp.first][temp.second.first][temp.second.second] + 1;
			map[z][y][x] = count;
			q.push({z,{y,x}});
		}
	}
}

int main(void)
{
	int m, n, h;
	int max;

	cin >> m >> n >> h;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					q.push({i, {j, k}});
			}
		}
	}

	chk_map(h, n, m);

	max = 0;
	for(int i = 0; i < h; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if (max < map[i][j][k])
					max = map[i][j][k];
				if (map[i][j][k] == 0)
				{
					cout << "-1";
					return (0);
				}
			}
		}
	}
	cout << max - 1;

	return (0);
}