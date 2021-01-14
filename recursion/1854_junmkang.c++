// codeup 1854 : [기초-재귀함수] 재귀로 각 자리 수의 합 리턴하기
#include <stdio.h>
#define lld long long int

lld f(lld n)
{
	if (n <= 0) return (0);
	return (n % 10) + f(n / 10);
}

int main(void)
{
	lld n;

	scanf("%lld", &n);
	printf("%lld", f(n));

	return (0);
}