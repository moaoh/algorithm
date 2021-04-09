// baekjoon N과 M (8)
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, m;
int value[10];
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
	for(int i = 0; i < n; i++)
	{
		if (value[k - 1] <= arr[i])
		{
			value[k] = arr[i];
			bfs(k + 1);
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	bfs(0);

	return (0);
}