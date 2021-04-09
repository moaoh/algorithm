#include <cstdio>

// (mod * a) % c

long long chk(long long a, long long b, long long c)
{
	if (b == 0) return (1);
	long long mod = chk(a, b / 2, c);
	printf("1_mod = %lld\n", mod);
	mod = mod * mod % c; // b * 2
	printf("2_mod = %lld\n", mod);
	if (b % 2 != 0) return mod = (mod * a) % c; // b + 1
	else return (mod);
}

int main(void)
{
	long long a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld", chk(a, b, c));

	return (0);
}