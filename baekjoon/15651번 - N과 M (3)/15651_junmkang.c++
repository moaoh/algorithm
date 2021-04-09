// baekjoon N과 M (3)
#include <stdio.h>

int n, m;
int arr[10];

void print(int i)
{
	if (i == m) return ;
	printf("%d ", arr[i]);
	print(i + 1);
}

void f(int k)
{
	if (k == m)
	{
		print(0);
		printf("\n");
		return ;
	}

	for(int i = 1; i <= n; i++)
	{
		arr[k] = i;
		f(k + 1);
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	f(0);

	return (0);
}