// baekjoon 연산자 끼워넣기 (2)
#include <stdio.h>
# define max 1000000001

int num[12];
int comp[5];

int n, big = -max, small = max;

void	info_num(int n)
{
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
}

void	info_comp(int n)
{
	for(int i = 0; i < n; i++)
		scanf("%d", &comp[i]);
}

void	f(int sum, int count, int p, int min, int mul, int d)
{
	if (count == n)
	{
		if (big < sum)
			big = sum;
		if (small > sum)
			small = sum;
		return ;
	}
	if (p > 0)
	{
		f(sum + num[count], count + 1, p - 1, min, mul, d);
	}
	if (min > 0)
	{
		f(sum - num[count], count + 1, p, min - 1, mul, d);
	}
	if (mul > 0)
	{
		f(sum * num[count], count + 1, p, min, mul - 1, d);
	}
	if (d > 0)
	{
		f(sum / num[count], count + 1, p, min, mul, d - 1);
	}
}

int main(void)
{
	scanf("%d", &n);
	info_num(n);
	info_comp(4);
	f(num[0], 1, comp[0], comp[1], comp[2], comp[3]);
	printf("%d\n%d", big, small);
}