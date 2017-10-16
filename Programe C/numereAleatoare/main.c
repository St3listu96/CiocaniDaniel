#include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 int main()
 {
   int nr_aleator, nr_in_05, zar;

   //srand(time(NULL) * clock());

   printf("ENTER pentru generarea unui nou set de numere,\ntasta+ENTER pentru a iesi\n\n");
   printf("numar aleator | numar in 0..5 | zar\n");

   do
   {
         nr_aleator = rand();  // rand returneaza un numar cuprins intre 0 si RAND_MAX (32767)
         nr_in_05   = nr_aleator % 6;  // Restul impartirii numarului returnat de rand la 6 va fi cuprins intre 0 si 5
         zar            = nr_in_05 + 1;  // Fata unui zar de table are intre 1 si 6 puncte

         printf("%-9d| %-9d| %-d", nr_aleator, nr_in_05, zar);
   }
   while (getchar() == '\n');

   return 0;
 }
