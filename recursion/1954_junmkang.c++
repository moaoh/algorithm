// 1954 : (재귀함수)삼각형 출력하기 2
#include <stdio.h>

int n;

void f(int a, int b)
{
	if (b == 0) return ;
	if (a < b) 
	{
		printf("*");
		f(++a, b);
	}
	else
	{
		printf("\n");
		f(0, --b);
	}
}

int main(void)
{
	scanf("%d", &n);
	f(0, n);

	return (0);
}
