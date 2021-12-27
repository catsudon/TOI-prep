#include <stdio.h>

int main(){

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    a = b-a;
    c = c-b;
    if(c>a){printf("%d",c-1);}
    else{printf("%d",a-1);}

}
