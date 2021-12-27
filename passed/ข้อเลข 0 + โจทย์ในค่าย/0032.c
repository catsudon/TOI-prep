#include<stdio.h>


int main(){

    int n;
    scanf("%d",&n);
    int num[n];
    int countzero=0;
    int i,j;
    for(i=0;i<n;i++){
        scanf("%d ",&num[i]);
        if(num[i]==0){
            countzero++;
        }

    }
    int temp;
    // SORT
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(num[j]<num[i]){
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    printf("%d",num[countzero]);
    for(i=0;i<countzero;i++){
        printf("0");
    }
    for(i=countzero+1;i<n;i++){
        printf("%d",num[i]);
    }

}
