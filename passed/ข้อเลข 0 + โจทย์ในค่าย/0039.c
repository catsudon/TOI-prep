#include<stdio.h>


int main(){

    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int tabemono[n];
    int damelist[m];
    int i,j,k;
    for(i=0;i<n;i++) tabemono[i] = i+1 ;
    for(i=0;i<m;i++) {
        scanf("%d",&k);
        damelist[i] = k+1;
    }
    int starter[n-m],count=0;
    for(i=0;i<n-m;i++){
        int indame = 0;
        for(j=0;j<m;j++){
            if(damelist[j]==tabemono[i]){
                indame=1;
                break;
            }
        if(indame==0) {
            starter[count] = tabemono[i];
            count++;
        }
        }
    }

    for(i=0;i<n-m;i++){
        printf("%d ",starter[i]);
        for(j=0;j<n;j++)
    }
}
