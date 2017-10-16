#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int suma (int x, int y){
    return x+y;
}

int isPalindrom(int x){
    int uc,rev=0,n=x;
    while(x){
        uc=x%10;
        x=x/10;
        rev=rev*10+uc;
    }
    if (rev == n)
        return 1;
    else
        return 0;
}

int isAnagram(char a[100],char b[100]){
    int i,j,l,k,p;
    char c;
    for(i=0;i<strlen(a);i++){
            c=a[i];
    for(j=0;j<strlen(a);j++){
        if (a[j]==c)
        k++;
        }
    }
    for(l=0;l<strlen(b);l++){
        if (b[l]==c)
        p++;
    }
if (p!=k)
    return 0;
else
    return 1;
    }


int main(){
    char a[]="cetoses",b[]="secetos";
    printf("%d",isAnagram(a,b));
    }
