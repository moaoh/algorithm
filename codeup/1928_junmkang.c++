// 1928 : (재귀함수) 우박수 (3n+1) (basic)
#include <stdio.h>

void	f(int n)
{
	printf("%d\n", n);
	if (n == 1) return ;
	if (n % 2 == 0) f(n / 2);
	else f(3 * n + 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	f(n);

	return (0);
}