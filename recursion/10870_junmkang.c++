#include <stdio.h>

int f(int n)
{
	if (n == 0) return (0);
	if (n == 1) return (1);
	if (n == 2) return (1);
	else return f(n-2) + f(n-1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
	return (0);
}