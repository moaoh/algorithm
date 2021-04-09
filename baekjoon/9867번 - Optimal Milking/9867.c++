// baekjoon Optimal Milking
// 풀지못하였음. 시간초과
#include <stdio.h>

int num[40001];
int max[40001];
int n, d;
int day_max;

void f(int sum, int i)
{
	if (i >= n){
		if (day_max < sum)
			day_max = sum;
		return ;
	}
	if (max[i] >= sum) return ;
	else max[i] = sum;
	f(sum + num[i + 2], i + 2);
	f(sum + num[i + 3], i + 3);
}

int main(void)
{
	int a, b;
	int sum;

	sum = 0;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for(int i = 0; i < d; i++)
	{
		scanf("%d %d", &a, &b);
		num[a - 1] = b;
		for(int j = 0; j < n; j++)
			max[j] = 0;
		f(num[0], 0);
		f(num[1], 1);
		sum += day_max;
	}
	printf("%d", sum);

	return (0);
}