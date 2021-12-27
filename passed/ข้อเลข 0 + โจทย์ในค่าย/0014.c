#include<stdio.h>

int main(){

    int a,b;
    scanf("%d %d",&a,&b);
    //find big num
    int max;
    int ans;
    if(a>b){max=a+1;}else{max=b+1;}
    for(int i=1;i<max;i++){
        if(a%i==0 && b%i==0){ans=i;}
    }
    printf("%d",ans);

}
