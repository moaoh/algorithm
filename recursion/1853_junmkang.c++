// 계단 오르기 2
#include <stdio.h>

int f(int n)
{
	if (n == 1) return 1;
	else return f(n - 1) + n;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", f(n));

	return (0);
}