// 1919 : (재귀 함수) 숫자 거꾸로 출력하기
#include <stdio.h>

void f(int n)
{
	if (n < 1) return ;
	printf("%d", n % 10);
	f(n / 10);
}

void chk(int n)
{
	if (n == 0) printf("0");
	else if (n % 10 == 0) chk(n / 10);
	else f(n);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	chk(n);
	return (0);
}