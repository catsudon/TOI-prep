#include<stdio.h>


int main(){

    int n;
    scanf("%d",&n);
    int col;
    if(n%2==0){
    col = n-1;
    }
    else{
    col = n;
    }
    int dat1 = col/2;
    int count = 0;
    // UPPER HALF
    for(int i=0;i<n/2;i++)
    {
    for(int j=0;j<dat1-i;j++){
        printf("-");
    }
    printf("*");
    if(i==0){}
    else{
    for(int k=0;k<1+(2*(i-1));k++){
        printf("-");
    }
    }
    if(i!=0){
    printf("*");
    }
    for(int l=0;l<dat1-i;l++){
        printf("-");
    }

    printf("\n");
    }
    if(n==1){
        printf("*");
    }
    else if(n%2==1){
        printf("*");
        for(int i=0;i<col-2;i++){
            printf("-");
        }
        printf("*");
        printf("\n");
    }

    // LOWER HALF
    for(int i=0;i<n/2;i++)
    {
        if(n%2==1){
            for(int l=0;l<i+1;l++){
            printf("-");
        }
        }
        else{
        for(int l=0;l<i;l++){
            printf("-");
        }
    }
    printf("*");
    if(n%2==0){for(int j=0;j<(col-2)-(2*i);j++){
        printf("-");
    }
    }
    else{
        for(int j=0;j<(col-2)-(2*i)-2;j++){
        printf("-");
    }
    }
    if(i!=n/2-1){
    printf("*");
    }
        if(n%2==1){
            for(int k=0;k<i+1;k++){
            printf("-");
        }
        }
        else{
            for(int k=0;k<i;k++){
        printf("-");
    }
        }
    printf("\n");

    }
}
