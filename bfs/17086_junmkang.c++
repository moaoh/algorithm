// 아기 상어 2
#include <iostream>
#include <queue>

using namespace std;

int map[51][51];
int chk[51][51];

int nx[] = {0, 1, 0, -1, 1, -1, -1, 1};
int ny[] = {1, 0, -1, 0, -1, 1, -1, 1};

queue<pair<int, int> > q;

void chk_map(int n, int m)
{
	int count = 0;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 8; k++)
		{
			int y = temp.first  + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || x < 0 || y >= n || x >= m) continue;
			if (map[y][x] != 0 || map[y][x] == 100) continue;
			count = map[temp.first][temp.second] + 1;
			map[y][x] = count;
			q.push({y, x});
		}
	}
}

int main(void)
{
	int n, m;
	int max;

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				map[i][j] = 100;
				q.push({i, j});
			}
		}
	
	chk_map(n, m);

	max = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if (map[i][j] != 100 && max < map[i][j] - 100)
			{
				max = map[i][j] - 100;
			}
		}
	cout << max;

	return (0);
}