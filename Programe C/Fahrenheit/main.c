#include <stdio.h>
#include <stdlib.h>

main(){
    int fahr, celsius;
    int prim, ultim, pas;
    prim=0; /* limita inferioara a temperaturii */
    ultim=300; /* limita superioara */
    pas=20; /* marimea pasului */
fahr = prim;
while (fahr <= ultim) {
celsius = 5 * (fahr-32) / 9;
printf("%d\t%d\n", fahr, celsius);
fahr = fahr + pas;
}
}



