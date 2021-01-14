// baekjoon N과 M (4)
#include <stdio.h>

int m, n;
int arr[10];

void f(int k)
{
	if (k == m)  {
		for(int i = 0; i < m; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if (arr[k - 1] <= i)
		{
			arr[k] = i;
			f(k + 1);
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	f(0);

	return (0);
}