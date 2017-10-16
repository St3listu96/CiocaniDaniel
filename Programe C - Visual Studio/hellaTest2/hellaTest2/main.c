#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>

void main() {
	int n;
	printf("Introduceti n-ul.\n");
	scanf("%d",&n);
	
	int multiplyBy4 = n << 2;

	printf("%d\n",multiplyBy4);

}