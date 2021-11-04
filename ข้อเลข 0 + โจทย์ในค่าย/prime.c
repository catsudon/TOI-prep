#include<stdio.h>

int isprime(int number){

for(int i=2;i<=number/2;i++){
    if(number%i==0){
        return 0;
    }
}
    return 1;


}




int main(){

int n;
int i,count=0;
scanf("%d",&n);
for(i=2;i<n+1;i++){
    int prime = isprime(i);
    if(prime==1) count++;
}

printf("%d",count);



}
