// baekjoon NxM 보드 완주하기 
#include <stdio.h>

char map[31][31];
int chk[31][31];

int n, m, num;
int f_small;

void dfs(int y, int x, int count)
{
	if (y == 0 || y == n - 1 || x == 0 || x == m - 1 || chk[y][x] != -1)
		count++;
	if (chk[y][x] == -1)
	{
		chk[y][x] = count;
		dfs(y + 1, x, count);
		dfs(y - 1, x, count);
		dfs(y, x + 1, count);
		dfs(y, x - 1, count);
	}
}

int small_chk(int i, int j)
{
	int temp = -1;
	
	for(int y = 0; y < n; y++)
		for(int x = 0; x < m; x++)
		{
			if (map[y][x] == '*')
				chk[y][x] = -2;
			if (map[y][x] == '.')
				chk[y][x] = -1;
		}
	dfs(i, j, 0);

	for(int y = 0; y < n; y++)
		for(int x = 0; x < m; x++)
		{
			if (chk[y][x] == -1) // .
				return (-1);
			else if (temp < chk[y][x])
				temp = chk[y][x];
		}
	return (temp);
}

int case_chk()
{
	f_small = -1;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (map[i][j] == '.')
			{
				num = small_chk(i, j);
				if (f_small == -1 || f_small > num)
					f_small = num;
			}
		}
	}

	return (f_small);
}

// 맵을 입력받음.
void map_info()
{
	for(int i = 0; i < n; i++)
		scanf("%s", map[i]);
}

// 맵 초기화.
void map_bzero()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			map[i][j] = 0;
}

int main(void)
{
	int small;
	int case_count = 0;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		case_count++;
		map_info(); // 맵을 받음.
		small = case_chk();
		printf("Case %d: %d", case_count, small);
		map_bzero(); // 맵 초기화.
	}

	return (0);
}