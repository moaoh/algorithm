// 보물섬
#include <iostream>
#include <queue>

using namespace std;

char	map[51][51];
int		chk[51][51];

int	chk_map(int l, int w, int i, int j)
{
	int count = 0;
	int nx[4] = {1, 0, -1, 0};
	int ny[4] = {0, 1, 0, -1};

	queue<pair<int, int> > q;
	chk[i][j] = count;
	count++;
	q.push({i, j});
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || x < 0 || y >= l || x >= w) continue;
			if (map[y][x] != 'L' || chk[y][x] != -1) continue;
			count = chk[temp.first][temp.second] + 1;
			chk[y][x] = count;
			q.push({y, x});
		}
	}
	return (count);
}

int main(void)
{
	int l, w;
	int max;

	cin >> l >> w;

	for(int i = 0; i < l; i++)
		for(int j = 0; j < w; j++)
			cin >> map[i][j];
	
	max = 0;
	for(int i = 0; i < l; i++)
	{
		for(int j = 0; j < w; j++)
		{
			if (map[i][j] == 'L')
			{
				int count = 0;
				for(int x = 0; x < l; x++)
					for(int y = 0; y < w; y++)
						chk[x][y] = -1;
				count = chk_map(l, w, i, j);
				if (count > max)
					max = count;
			}
		}
	}
	cout << max;

	return (0);
}