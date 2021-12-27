#include<stdio.h>



typedef struct{

int count;
int number;

}looblike;


int main(){

int i;

int n;
scanf("%d",&n);
int numlist[n];
int maxnum=0;
for(i=0;i<n;i++){

    scanf("%d",&numlist[i]);
    if(numlist[i]>maxnum) maxnum=numlist[i];

}
//printf("%d",maxnum);

looblike loob[maxnum+1];
for(i=0;i<maxnum+1;i++){
    loob[i].number = i;
    loob[i].count = 0;
}
for(i=0;i<n;i++){
    loob[numlist[i]].count+=1;
}

// count max
int max=0;
looblike biggest;
for(i=0;i<maxnum+1;i++){
    if(loob[i].count>max){
        max = loob[i].count;
        biggest = loob[i];
    }
}
//printf("%d ",biggest.number);
for(i=0;i<maxnum+1;i++){
    if(biggest.count==loob[i].count){
        printf("%d ",loob[i].number);
    }
}
}
