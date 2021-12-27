#include<stdio.h>

int main(){

int score[5][4];
    for(int i=0;i<5;i++){
        scanf("%d %d %d %d",&score[i][0],&score[i][1],&score[i][2],&score[i][3]);
    }
int sum[5]={0,0,0,0,0};
for(int i=0;i<5;i++){
    for(int j=0;j<4;j++){
        sum[i]= sum[i]+score[i][j];
    }
}
int note=0;
int max=sum[0];
for(int i=0;i<5;i++){
    if(max<sum[i]){
        max=sum[i];
        note=i;
    }
}
printf("%d %d",note+1,sum[note]);
}
