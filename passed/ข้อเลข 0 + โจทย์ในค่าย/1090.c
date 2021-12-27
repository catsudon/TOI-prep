#include<stdio.h>


int main(){

int N,A;
int i,j;
scanf("%d",&N);
int cock[1000000];
for(i=0;i<N;i++){
    scanf("%d",&cock[i]);
}
scanf("%d",&A);
int count=0;
for(i=0;i<N;i++){
    for(j=i+1;j<N;j++){
        if(cock[i]+cock[j]==A){
        count++;
        }
    }
}
printf("%d",count);
}
