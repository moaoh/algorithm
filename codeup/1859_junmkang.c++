// 1859 : [기초-재귀함수] 별 삼각형 출력하기
#include <stdio.h>

int n;

void f(int a, int b)
{
	if (a == n) return ;
	if (a < b) 
	{
		printf("*");
		f(++a, b);
	}
	else
	{
		printf("\n");
		f(0, ++b);
	}
}

int main(void)
{
	scanf("%d", &n);
	f(0, 1);

	return (0);
}
