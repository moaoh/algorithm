// codeup 3702 : 파스칼의 삼각형 2
#include <stdio.h>

int memo[51][51];

int f(int r, int c)
{
	if (r == 1 || c == 1) return (memo[r][c] = 1);
	if (memo[r][c]) return memo[r][c];
	return memo[r][c] = (f(r - 1, c) + f(r, c - 1)) % 100000000;
}

int main(void)
{
	int r, c;

	scanf("%d %d", &r, &c);
	printf("%d", f(r, c));

	return (0);
}