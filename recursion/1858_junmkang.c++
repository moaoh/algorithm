// 1858 : [기초-재귀함수] 파스칼의 삼각형 출력하기 1
#include <stdio.h>

int memo[26][26];

int f(int n, int r)
{
	if (r == 1 || n == r) return (memo[n][r] = 1);
	if (memo[n][r]) return (memo[n][r]);
	return (memo[n][r] = f(n - 1, r - 1) + f(n - 1, r));
}

int main(void)
{
	int n, r;
	scanf("%d %d", &n, &r);
	printf("%d", f(n, r));

	return (0);
}