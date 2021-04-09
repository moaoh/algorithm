// 2605 : 캔디팡
#include <stdio.h>
#define cn 7

int map[9][9];

void f(int c, int *count, int y, int x)
{
	if (map[y][x] == c)
	{
		*count += 1;
		map[y][x] = 0;
		f(c, count, y + 1, x);
		f(c, count, y - 1, x);
		f(c, count, y, x + 1);
		f(c, count, y, x - 1);
	}
}

int main(void)
{
	int count, num;

	for(int i = 0; i < cn; i++)
		for(int j = 0; j < cn; j++)
			scanf("%d", &map[i][j]);
	
	num = 0;
	for(int i = 0; i < cn; i++)
		for(int j = 0; j < cn; j++)
			if (map[i][j] != 0)
			{
				count = 0;
				f(map[i][j], &count, i, j);
				if (count >= 3)
					num++;
			}
	printf("%d", num);

	return (0);
}