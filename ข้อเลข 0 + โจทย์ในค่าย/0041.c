#include<stdio.h>

int main(){


    int n;
    scanf("%d",&n);
    if(n%2==0){
        float ans = n;
        printf("%f",ans);
    }
    else if(n==3){
        printf("4");
    }
    else{
        float ans = n+0.464102;
        printf("%f",ans);
    }

}
