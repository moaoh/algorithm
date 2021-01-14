// 적록색약
#include <iostream>
#include <queue>

using namespace std;

char RGB_map[101][101];
char RB_map[101][101];

int nx[4] = {0, 1, 0, -1};
int ny[4] = {1, 0, -1, 0};

void RGB_map_chk(int n, int i, int j, char color)
{
	queue<pair<int, int> > q;
	q.push({i, j});
	RGB_map[i][j] = 'X';
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (RGB_map[y][x] != color) continue;
			RGB_map[y][x] = 'X';
			q.push({y, x});
		}
	}
}

void RB_map_chk(int n, int i, int j, char color)
{
	queue<pair<int, int> > q;
	q.push({i, j});
	RB_map[i][j] = 'X';
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (x < 0 || x >= n || y < 0 || y >= n) continue;
			if (RB_map[y][x] != color) continue;
			RB_map[y][x] = 'X';
			q.push({y, x});
		}
	}
}

void chk_map(int n)
{
    int RGB_count, RB_count;

    RGB_count = RB_count = 0;
    for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (RGB_map[i][j] != 'X')
			{
				RGB_count++;
                if (RGB_map[i][j] == 'R')
                    RGB_map_chk(n, i, j, 'R');
                if (RGB_map[i][j] == 'G')
                    RGB_map_chk(n, i, j, 'G');
                if (RGB_map[i][j] == 'B')
                    RGB_map_chk(n, i, j, 'B');
			}
			if (RB_map[i][j] != 'X')
			{
				RB_count++;
                if (RB_map[i][j] == 'R')
                    RB_map_chk(n, i, j, 'R');
                if (RB_map[i][j] == 'B')
                    RB_map_chk(n, i, j, 'B');
			}
		}
	}
    cout << RGB_count << " " << RB_count;
}

int main(void)
{
	int n;
	char c;

    cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> c;
			if (c == 'R' || c == 'G')
				RB_map[i][j] = 'R';
			else RB_map[i][j] = 'B';
			RGB_map[i][j] = c;
		}
	}
    chk_map(n);

	return (0);
}