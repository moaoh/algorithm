// baekjoon N-Queen
#include <stdio.h>

int n, count;

int queue[16];

int chk(int y)
{
	for(int cy = 0; cy < y; cy++)
	{
		if (queue[cy] == queue[y]) return 0; // y
		if (queue[y] - queue[cy] == y - cy) return 0;
		if (queue[cy] - queue[y] == y - cy) return 0;
	}
	return (1);
}

void f(int y)
{
	if (n == y)
	{
		count++;
		return ;
	}
	for(int i = 0; i < n; i++)
	{
		queue[y] = i;
		if (chk(y)) f(y + 1);
	}
}

int main(void)
{
	scanf("%d", &n);
	f(0);
	printf("%d", count);

	return (0);
}