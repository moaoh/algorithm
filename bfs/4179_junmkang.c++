// 불!
#include <iostream>
#include <queue>

using namespace std;

char	map[1001][1001];
int		j_chk[1001][1001];
int		f_chk[1001][1001];

queue<pair<int, int> > j_q;
queue<pair<int, int> > f_q;

int	ny[] = {0, 1, 0, -1};
int nx[] = {1, 0, -1, 0};

void	f_bfs(int r, int c)
{
	int count = 0;

	while(!f_q.empty())
	{
		pair<int, int> temp = f_q.front();
		f_q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || y >= r || x < 0 || x >= c) continue;
			if (map[y][x] == '#' || f_chk[y][x] != -1) continue;
			count = f_chk[temp.first][temp.second] + 1;
			f_chk[y][x] = count;
			f_q.push({y, x});
		}
	}
}

int		j_bfs(int r, int c)
{
	int count = 0;
	
	while(!j_q.empty())
	{
		pair<int, int> temp = j_q.front();
		j_q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || y >= r || x < 0 || x >= c) {
				cout << j_chk[temp.first][temp.second] + 1;
				return (0);
			}
			if (map[y][x] == '#' || j_chk[y][x] >= 0) continue;
			if ((f_chk[y][x] >= 0 && f_chk[y][x] <= count + 1)) continue;
			count = j_chk[temp.first][temp.second] + 1;
			j_chk[y][x] = count;
			j_q.push({y, x});
		}
	}
	cout << "IMPOSSIBLE";
	return (0);
}

int main(void)
{
	int r, c;

	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			f_chk[i][j] = -1;
			j_chk[i][j] = -1;
			if (map[i][j] == 'J')
			{
				j_q.push({i, j});
				j_chk[i][j] = 0;
			}
			if (map[i][j] == 'F')
			{
				f_q.push({i, j});
				f_chk[i][j] = 0;
			}
		}

	f_bfs(r, c);
	j_bfs(r, c);


	return (0);
}