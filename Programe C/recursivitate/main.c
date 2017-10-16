#include<stdio.h>
#include<conio.h>

void main()
{
	int n,U0=0,U1=1,U2;
	int i;
	printf("n="); scanf("%d",&n);
	if(!n) printf("%d",U0);
	else
		if (n==1) printf("%d",U1);
		else
		{
			for (i=2;i<=n;i++)
			{
				U2=U0+U1;
				U0=U1;
				U1=U2;
			}
			printf("%d",U2);
		}
/*
ptr. n=3
i=2: U2=U0+U1
U0=U1
U1=U2
i=3: U2=U1+U2
*/
	getch();
}
