// 1860 : [기초-재귀함수] 수 삼각형 출력하기
#include <stdio.h>

int n;

void f(int a, int b)
{
	if (a == n + 1) return ;
	if (a <= b) {
		printf("%d ", a);
		f(a + 1, b);
	}
	else {
		printf("\n");
		f(1, b + 1);
	}
}

int main(void)
{
	scanf("%d", &n);
	f(1, 1);

	return (0);
}