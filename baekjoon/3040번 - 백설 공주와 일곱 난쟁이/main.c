#include <stdio.h>

int a[10];

int main(void)
{

	int sum = 0;
	for(int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	for(int i = 0; i < 9; i++) {
		for(int j = i+1; j < 9; j++) {
			if(sum - a[i] - a[j] == 100) {
				a[i] = 0;
				a[j] = 0;
				goto EXIT;
			}
		}
	}
	EXIT:
	for(int i = 0; i < 9; i++) {
		if(a[i] != 0) {
			printf("%d\n", a[i]);
		}
	}
	
	return 0;
}