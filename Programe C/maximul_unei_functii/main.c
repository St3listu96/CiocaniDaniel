#include <stdlib.h>
#include <stdio.h>

#include <math.h>

float maxim_functie(float (*functie)(float),float a, float b,int n)

{

float valtemp,interval,i,maxim=-999999999;

interval=(b-a)/n;

for(i=a;i<=b;i=i+interval)

{

valtemp=(*functie)(i);

if(valtemp>maxim)

maxim=valtemp;

}

return maxim;

}

float f1(float x)

{

return sqrt(x*x+1);

}

float f2(float x)

{

return pow(x,3);

}

float f3(float x)

{

return exp(x+1);

}


int main()

{

int a,b,n;

printf("Introduceti intervalul [a,b] si numarul de diviziuni al acestuia , n,echidistante.");

printf("a= ");scanf("%d",&a);
    printf("b= ");scanf("%d",&b);

printf("n= ");scanf("%d",&n);

printf("Maximul functiei Sqrt(x^2+1) = %f\n",maxim_functie(f1,a,b,n));

printf("Maximul functiei x^3 = %f\n",maxim_functie(f2,a,b,n));

printf("Maximul functiei Exp(x+1) = %f\n",maxim_functie(f3,a,b,n));

return 0;
}
