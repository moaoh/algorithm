// codeup 1904 : (재귀함수) 두 수 사이의 홀수 출력하기
#include <stdio.h>

void f(int a, int b)
{
	if (a > b) return ;
	if (a % 2 != 0) printf("%d ", a);
	f(a + 1, b);
}

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);
	f(a, b);
	return (0);
}