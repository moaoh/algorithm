// 1929 : (재귀함수) 우박수 (3n+1) (reverse)
#include <stdio.h>

void	f(int n)
{
	if (n == 1) {
		printf("%d\n", n);
		return ;
	}
	if (n % 2 == 0) f(n / 2);
	else f(3 * n + 1);
	printf("%d\n", n);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	f(n);

	return (0);
}