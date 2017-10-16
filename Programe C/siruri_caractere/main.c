#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void maxi ( char s[], char maxim[], char minim[])
{
    char *p;
    int m,n;
    p= strtok(s, " ");
    strcpy(maxim,p);
    strcpy(minim,p);
    m=strlen(p);
    n=strlen(p);
    while(p!=NULL)
    {
        if(strlen(p)>m)
        {
            strcpy(maxim,p);
            m=strlen(p);
        }
        if(strlen(p)<n)
        {
            strcpy(minim,p);
            n=strlen(p);
        }
        p=strtok(NULL, " ");
    }
}
int main()
{
    int n;
    int i;
    int ok;
    char **s=(char **)malloc(20*sizeof(char*)), maxim[20], minim[20];
    if(*s==NULL)
        printf("Nu exista memorie!\n");
    else
    {
        ok=1;
        for(i=0;i<20&&ok;i++)
        {
        s[i]=malloc(40*sizeof(char));
        if(s[i]==NULL)
            ok=0;
        }
        if (ok)
            printf("Este destula memorie!\n");
        else
            printf("Nu exista destula memorie!\n");
    }
    i=0;
    printf("Prop %d este: ", i);
    fgets(s[i],40,stdin);
    while(s[i][0]!='\n'){
        strcpy(s[i]+strlen(s[i])-1, s[i]+strlen(s[i]));
        i++;
        printf("Prop %d este: ", i);
        fgets(s[i],40,stdin);
    }
    n=i-1;
    for(i=0;i<=n;i++){
        maxi(s[i], maxim, minim);
        printf("Maxim prop %d: \"%s\" si minim prop %d: \"%s\".", i,maxim, i, minim);
        printf("\n");
    }
    return 0;
}


