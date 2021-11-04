#include<stdio.h>

int main(){

int num[5];
scanf("%d %d %d %d",&num[0],&num[1],&num[2],&num[3]);
for(int i=0;i<4;i++){
    for(int j=i;j<4;j++){
        if(num[j]>num[i]){
            num[5]=num[i];
            num[i]=num[j];
            num[j]=num[5];
        }
    }
}
int w = num[1];
int h = num[3];
printf("%d",w*h);

}
