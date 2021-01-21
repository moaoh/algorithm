// baekjoon 감시
// https://jongnan.tistory.com/entry/%EB%B0%B1%EC%A4%80-15683-%EA%B0%90%EC%8B%9C 참고
#include <iostream>
#include <cstdio>
#include <vector>
#define MAX 8

using namespace std;

vector <int> cctv;
vector <pair <int, int> > v;

int map[MAX][MAX];
int n, m;
int zero_num, cctv_num;
int small = 65;

void bfs(int y, int x, int dir)
{
	// 동
	if (dir == 0)
	{
		x = x + 1;
		if (x >= m) return ;
		if (map[y][x] == 6) return ;
		map[y][x] = -1;
		bfs(y, x, dir);
	}
	// 남
	if (dir == 1)
	{
		y = y + 1;
		if (y >= n) return ;
		if (map[y][x] == 6) return ;
		map[y][x] = -1;
		bfs(y, x, dir);
	}
	// 서
	if (dir == 2)
	{
		x = x - 1;
		if (x < 0) return ;
		if (map[y][x] == 6) return ;
		map[y][x] = -1;
		bfs(y, x, dir);
	}
	// 북
	if (dir == 3)
	{
		y = y - 1;
		if (y < 0) return ;
		if (map[y][x] == 6) return ;
		map[y][x] = -1;
		bfs(y, x, dir);
	}
}

void MapCopy(int (*a)[MAX], int (*b)[MAX]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = b[i][j];
		}
	}
}

void map_print()
{
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}

void zero_count()
{
	int count = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				count++;
		}
	if (small > count)
	{
		// map_print();
		small = count;
	}
}

void solution(int count)
{
	if (count == cctv_num)
	{
		zero_count();
		return ;
	}
	
	int y = v[count].first;
	int x = v[count].second;
	int chk_board[MAX][MAX];

	if (cctv[count] == 1)
	{
		for(int i = 0; i < 4; i++)
		{
			MapCopy(chk_board, map);
			bfs(y, x, i);
			solution(count + 1);
			MapCopy(map, chk_board);
		}
	}
	if (cctv[count] == 2)
	{
		for(int i = 0; i < 2; i++)
		{
			MapCopy(chk_board, map);
			bfs(y, x, i % 4);
			bfs(y, x, (i + 2) % 4);
			solution(count + 1);
			MapCopy(map, chk_board);
		}
	}
	
	if (cctv[count] == 3)
	{
		for(int i = 0; i < 4; i++)
		{
			MapCopy(chk_board, map);
			bfs(y, x, i % 4);
			bfs(y, x, (i + 1) % 4);
			solution(count + 1);
			MapCopy(map, chk_board);
		}
	}

	if (cctv[count] == 4)
	{
		for(int i = 0; i < 4; i++)
		{
			MapCopy(chk_board, map);
			bfs(y, x, i % 4);
			bfs(y, x, (i + 1) % 4);
			bfs(y, x, (i + 2) % 4);
			solution(count + 1);
			MapCopy(map, chk_board);
		}
	}

	if (cctv[count] == 5)
	{
		MapCopy(chk_board, map);
		bfs(y, x, 0);
		bfs(y, x, 1);
		bfs(y, x, 2);
		bfs(y, x, 3);
		solution(count + 1);
		MapCopy(map, chk_board);
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
				cctv.push_back(map[i][j]);
				cctv_num++;
				v.push_back({i, j});
			}
			else zero_num++;
		}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	map_info();
	solution(0);
	printf("%d", small);

	return (0);
}