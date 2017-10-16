#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	int random;
	int ct = 0;
	srand(time(NULL));
	int i;
	for (i = 0; i < 10; i++) {
		random = rand();
		random = random % 2;
		if (random == 1)
			ct++;
	}

	if (ct > 4)
		printf("Piedone este teapan. (%d din 10)\n", ct);
	else
		printf("Piedone nu este teapan. (%d din 10)\n",ct);
}