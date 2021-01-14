// 하노이 탑 이동 순서
#include <stdio.h>

void f(int a, int b, int n)
{
	if (n == 1){
		printf("%d %d\n", a, b);
		return ;
	}
	f(a, 6-a-b, n-1);
	printf("%d %d\n", a, b);
	f(6-a-b, b, n-1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", (1<<n)-1);
	f(1, 3, n);

	return (0);
}