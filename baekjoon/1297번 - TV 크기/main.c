#include <stdio.h>
#include <math.h>

// 피타고라스 a2 + b2 = c2 

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x = (a*b) / sqrt(b*b + c*c);
	int y = (a*c) / sqrt(b*b + c*c);
	printf("%d %d", x, y);
	
	return 0;
}