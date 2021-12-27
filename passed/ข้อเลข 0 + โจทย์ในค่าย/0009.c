#include<stdio.h>

int main(){

    int num[4];
    char alp[4];
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    scanf("%s",alp);
for(int i=0;i<3;i++){
        int j=0;
    while(j<3){
        if(num[j]<num[i]){
            num[3]=num[i];
            num[i]=num[j];
            num[j]=num[3];

        }
    j++;}
}
if(alp[0]=='A'){
    printf("%d ",num[2]);
}
if(alp[0]=='B'){
    printf("%d ",num[1]);
}
if(alp[0]=='C'){
    printf("%d ",num[0]);
}
if(alp[1]=='A'){
    printf("%d ",num[2]);
}
if(alp[1]=='B'){
    printf("%d ",num[1]);
}
if(alp[1]=='C'){
    printf("%d ",num[0]);
}
if(alp[2]=='A'){
    printf("%d ",num[2]);
}
if(alp[2]=='B'){
    printf("%d ",num[1]);
}
if(alp[2]=='C'){
    printf("%d ",num[0]);
}
}
