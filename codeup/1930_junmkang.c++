// 1930 : SuperSum
#include <stdio.h>

int dp[15][15];

int		supersum(int k, int n)
{
	if (k == 0) return n;
	if (dp[k][n]) return dp[k][n];
	if (n == 1) return dp[k][n] = supersum(k - 1, n);
	return dp[k][n] = supersum(k , n - 1) + supersum(k - 1, n);
}

int		main(void)
{
	int k, n;

	while (scanf("%d %d", &k, &n) != EOF)
	{
		printf("%d\n", supersum(k, n));
	}
	return (0);
}