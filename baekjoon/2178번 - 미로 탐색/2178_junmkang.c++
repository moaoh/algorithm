// 미로 탐색
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];
int	cot[101][101];

void chk_map(int n, int m)
{
	int count = 0;
	int nx[4] = {0, 1, 0, -1};
	int ny[4] = {1, 0, -1, 0};

	queue<pair<int, int> > q;
	q.push({0, 0});
	count++;
	cot[0][0] = count;
	while(!q.empty())
	{
		pair<int, int> temp = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int y = temp.first + ny[k];
			int x = temp.second + nx[k];
			if (x < 0 || y < 0 || y >= n || x >= m) continue;
			if (map[y][x] != 1 || cot[y][x] != 0) continue;
			count = cot[temp.first][temp.second] + 1;
			cot[y][x] = count;
			q.push({y, x});
		}
	}
}

int main(void)
{
	int n, m;

	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);

	chk_map(n, m);
	cout << cot[n-1][m-1];

	return (0);
}