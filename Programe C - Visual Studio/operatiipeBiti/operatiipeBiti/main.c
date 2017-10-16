#include <stdio.h>
#include <stdlib.h>

void afisare(int n) {
	int i;
	int bit = 0;
	for (i = 0; i<8; i++) {
		bit = (n << i) >> 7;
		if (bit < 0)
			bit *= -1; 
		printf("%d", bit);
	}
}

void schimbare(int number,int n,int p) {
	int i;
	int bit = 0;
	for (i = 0; i<8; i++) {
		if ((i >= (8 -p - n)) && (i < (8 -p))) {
			bit = (n << i) >> 7;
			bit = bit ^ 1;
			if (bit < 0)
				bit *= -1;
			printf("%d",bit);
		}
		else {
			bit = (n << i) >> 7;
			if (bit < 0)
				bit *= -1;
			printf("%d", bit);
		}
	}
}

int main() {
	int numar;

	printf("Introduceti numarul.\n");
	scanf("%d",&numar);

	//afisare(numar);
	schimbare(numar, 1, 2);
	return 0;
}