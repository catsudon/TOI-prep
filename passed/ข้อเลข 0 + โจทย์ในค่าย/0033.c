#include<stdio.h>

typedef struct{

int num;
int order;


}number;


int main(){

int n;
scanf("%d",&n);
number set[n];
int i,j;
for(int i=0;i<n;i++){
    if(i==n-1){
        scanf("%d",&set[i].num);
        set[i].order = i+1;
    }
    else{
        scanf("%d ",&set[i].num);
        set[i].order = i+1;
    }

}
number temp;
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(set[j].num>set[i].num){
            temp = set[i];
            set[i] = set[j];
            set[j] = temp;
        }
        else if(set[i].num==set[j].num){
            if(set[j].order<set[i].order){
                temp = set[i];
                set[i] = set[j];
                set[j] = temp;
            }
        }
    }
}

printf("%d ",set[0].order);
for(i=1;i<n;i++){
    if(set[i].num==set[0].num){
        printf("%d ",set[i].order);
    }
    else{
        break;
    }
}

}
