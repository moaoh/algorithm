// 양
#include <iostream>
#include <queue>

using namespace std;

char	map[251][251];
int		s, w;

void	chk_map(int i, int j, int r, int c)
{
	int y, x;
	int	nx[4] = {0, 1, 0, -1};
	int	ny[4] = {1, 0, -1, 0};

	s = w = 0;
	queue<pair<int, int> > q;
	if (map[i][j] == 'o') s++;
	else if (map[i][j] == 'v') w++;
	map[i][j] = '#';
	q.push({i, j});
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			y = temp.first + ny[k];
			x = temp.second + nx[k];
			if (y < 0 || x < 0 || y >= r || x >= c) continue;
			if (map[y][x] == '#') continue;
			if (map[y][x] == 'o') s++;
			else if (map[y][x] == 'v') w++;
			map[y][x] = '#';
			q.push({y, x});
		}
	}
}

int		main(void)
{
	int r, c;
	int sum_s, sum_w;

	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> map[i][j];
	
	sum_s = 0;
	sum_w = 0;
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			if (map[i][j] != '#')
			{
				s = w = 0;
				chk_map(i, j, r, c);
				if (s > w) sum_s += s;
				else sum_w += w;
			}
		}
	}
	cout << sum_s << " " << sum_w;

	return (0);
}