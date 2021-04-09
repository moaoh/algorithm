// baekjoon N과 M (10)
#include <iostream>
#include <algorithm>
#include <cstdio>

int n, m;
int value[10];
int chk[10];
int arr[10];

void bfs(int k)
{
	if (k == m)
	{
		for(int i = 0; i < m; i++)
			printf("%d ", value[i]);
		printf("\n");
		return ;
	}
	int memo = 0;
	for(int i = 0; i < n; i++)
	{
		if (chk[i] || (memo == arr[i]) || value[k - 1] > arr[i])
			continue ;
		value[k] = arr[i];
		memo = arr[i];
		chk[i] = 1;
		bfs(k + 1);
		chk[i] = 0;
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	bfs(0);

	return (0);
}