// 탈출
#include <iostream>
#include <queue>

using namespace std;

char map[51][51];
int	mul_chk[51][51];
int	go_chk[51][51];

queue<pair<int, int> > mul_q;
queue<pair<int, int> > go_q;

int ny[] = {0, 1, 0, -1};
int nx[] = {1, 0, -1, 0};

void	get_map(int r, int c)
{
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			mul_chk[i][j] = -1;
			go_chk[i][j] = -1;
			if (map[i][j] == 'S')
			{
				go_q.push({i, j});
				go_chk[i][j] = 0;
			}
			if (map[i][j] == '*')
			{
				mul_q.push({i, j});
				mul_chk[i][j] = 0;
			}
		}
}

void	mul_map(int r, int c)
{
	while(!mul_q.empty())
	{
		pair<int, int> temp = mul_q.front();
		mul_q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || y >= r || x < 0 || x >= c) continue;
			if (mul_chk[y][x] != -1 || map[y][x] == 'X') continue;
			if (map[y][x] == 'D') continue;
			mul_chk[y][x] = mul_chk[temp.first][temp.second] + 1;
			mul_q.push({y, x});
		}
	}
}

int		go_map(int r, int c)
{
	while(!go_q.empty())
	{
		pair<int, int> temp = go_q.front();
		go_q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (y < 0 || y >= r || x < 0 || x >= c) continue;
			if ((mul_chk[y][x] != -1 && mul_chk[y][x] <= go_chk[temp.first][temp.second] + 1)) continue;
			if (map[y][x] == 'X' || go_chk[y][x] != -1) continue;
			if (map[y][x] == 'D')
			{
				cout << go_chk[temp.first][temp.second] + 1;
				return (0);
			}
			go_chk[y][x] = go_chk[temp.first][temp.second] + 1;
			go_q.push({y, x});
		}
	}
	cout << "KAKTUS";
	return (0);
}

int		main(void)
{
	int r, c;

	cin >> r >> c;
	get_map(r, c);
	mul_map(r, c);
	go_map(r, c);

	return (0);
}