#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct puncte{
    int x;
    int y;
    float distanta;
};

void citire(struct puncte *p){
    printf("Introduceti coordonata x!\n");
    scanf("%d",&(*p).x);
    printf("Introduceti coordonata y!\n");
    scanf("%d",&(*p).y);
}

float minimDistanta(struct puncte *p,int n){
    int i;
    float min=1000000;
    for(i=0;i<n;i++){
        p[i].distanta=sqrt(pow(p[i+1].x-p[i].x,2)+pow(p[i+1].y-p[i].y,2));
        if(min>p[i].distanta)
            min=p[i].distanta;
    }
    return min;
}
int main()
{
    int i=0;
    int n=0;
    struct puncte a[100];
    citire(&a[0]);
    while(a[i].x!=0 && a[i].y!=0){
        citire(&a[i+1]);
        i++;
        n++;
    }
    printf("Distanta cea mai mica dintre puncte este: %.2f ",minimDistanta(a,n));
    return 0;
}
