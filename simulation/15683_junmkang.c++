// baekjoon 감시
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue <pair <int, int> > q;

int map[10][10];
int chk_board[10][10];
int cctv[6];
int n, m;
int zero_num;
int small;

void bfs(int y, int x, int dir)
{
}

void map_cpy()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			chk_board[i][j] = map[i][j];

}

void zero_count()
{
	int count = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if (chk_board[i][j] == 0)
				count++;
		}
	if (small > count)
		small = count;
}

void solution(int count)
{

	if (count == zero_num)
	{
		zero_count();
		return ;
	}
	pair <int, int> t = q.front(); q.pop();
	if (map[t.first][t.second] = 1 && cctv[1] > 0)
	{
		cctv[1]--;
		for(int i = 0; i < 4; i++)
		{
			bfs(t.first, t.second, i % 4);
			solution(count + 1);
			map_cpy();
		}
	}
	// 동 서 <-->
	if (map[t.first][t.second] = 2 && cctv[2] > 0)
	{
		cctv[2]--;
		for(int i = 0; i < 2; i++)
		{
			bfs(t.first, t.second, i % 4);
			bfs(t.first, t.second, i + 2 % 4);
			solution(count + 1);
			map_cpy();
		}
	}
	
	if (map[t.first][t.second] = 3 && cctv[3] > 0)
	{
		cctv[3]--;
		for(int i = 0; i < 4; i++)
		{
			bfs(t.first, t.second, i % 4);
			bfs(t.first, t.second, i + 1 % 4);
			solution(count + 1);
			map_cpy();
		}
	}

	if (map[t.first][t.second] = 4 && cctv[4] > 0)
	{
		cctv[4]--;
		for(int i = 0; i < 4; i++)
		{
			bfs(t.first, t.second, i % 4);
			bfs(t.first, t.second, i + 1 % 4);
			bfs(t.first, t.second, i + 2 % 4);
			map_cpy();
		}
	}

	if (map[t.first][t.second] = 5 && cctv[5] > 0)
	{
		cctv[5]--;
		bfs(t.first, t.second, 0);
		bfs(t.first, t.second, 1);
		bfs(t.first, t.second, 2);
		bfs(t.first, t.second, 3);
		solution(count + 1);
		map_cpy();
	}
}

void map_info()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				q.push({i, j});
				zero_num++;
				cctv[map[i][j]]++;
			}
		}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	map_info();
	solution(0);

	return (0);
}