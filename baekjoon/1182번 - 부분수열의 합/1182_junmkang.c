// baekjoon 부분수열의 합
#include <stdio.h>

int n, s, cnt;

int arr[21];

void dfs(int k, int sum)
{
	if (k > n) return ;
	if (k == n && sum == s)
		cnt++;
	dfs(k + 1, sum);
	dfs(k + 1, sum + arr[k]);
}

int main(void)
{
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	if (s == 0) cnt--;
	dfs(0, 0);
	printf("%d", cnt);
	
	return (0);
}