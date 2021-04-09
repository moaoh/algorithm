// 쉬운 최단거리
#include <iostream>
#include <queue>

using namespace std;

int	map[1001][1001];
int	cot[1001][1001];

void	change_map(int n, int m, int i, int j)
{
	int	count = 0;
	int nx[4] = {0, 1, 0, -1};
	int ny[4] = {1, 0, -1, 0};

	queue<pair<int, int> > q;
	q.push({i, j});
	cot[i][j] = 0;
	count++;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (x < 0 || y < 0 || y >= n || x >= m) continue;
			if (map[y][x] == 0 || cot[y][x] != -1) continue;
			count = cot[temp.first][temp.second] + 1;
			cot[y][x] = count;
			q.push({y, x});
		}
	}
}

int main(void)
{
	int n, m;
	int	ch_i, ch_j;

	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				ch_i = i;
				ch_j = j;
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cot[i][j] = -1;

	change_map(n, m, ch_i, ch_j);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (cot[i][j] == -1 && map[i][j] == 0) cout << "0" << ' ';
			else if (cot[i][j] == -1) cout << "-1" << ' ';
			else cout << cot[i][j] << ' ';
		}
		cout << "\n";
	}

	return (0);
}