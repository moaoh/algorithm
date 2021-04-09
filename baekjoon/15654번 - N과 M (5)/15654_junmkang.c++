// baekjoon N과 M (5)
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];
int chk[10];
int value[10];
int m, n;

void bfs(int k)
{
	if (k == m)
	{
		for(int i = 0; i < m; i++)
			printf("%d ", value[i]);
		printf("\n");
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (!chk[i])
		{
			value[k] = arr[i];
			chk[i] = 1;
			bfs(k + 1);
			chk[i] = 0;
		}
	}

}

int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr+n);
	bfs(0);

	return (0);
}