#include <stdio.h>

int t[100001];

int f(int n) {
	if(n == 0) return 1;
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(t[n] != 0) return t[n];
	return t[n] = (f(n-1) + f(n-2) + f(n-3)) % 1000;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
	
	return 0;
}