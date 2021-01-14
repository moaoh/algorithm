// 1920 : (재귀함수) 2진수 변환
#include <stdio.h>

void	f(int n)
{
	if (n == 0) return ;
	f(n / 2);
	printf("%d", n % 2);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	if (n == 0) printf("0");
	else f(n);

	return (0);
}