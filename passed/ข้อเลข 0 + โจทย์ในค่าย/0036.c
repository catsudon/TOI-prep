#include<stdio.h>


int main(){

    long long int n;
    long long int ans=1;
    long long int suanhan=1;
    scanf("%lld",&n);
    if(n==1){
        printf("2");
    }
    else if(n%2==0){
        unsigned long long int chance = n/2;
        for(int i=n;i>chance;i--){
            ans = ans*i;
        }
        for(int i=1;i<chance+1;i++){
            suanhan = suanhan*i;
        }
        long long int finnnnn = ans/suanhan;
        printf("%lld",finnnnn);
    }
    else{
        unsigned long long int chance = n/2; //2
   //     printf("chance %d\n",chance);
        for(int i=n;i>chance;i--){
            ans = ans*i; //60
        }
        long long int lol;
        for(int i=1;i<chance+2;i++){
            suanhan = suanhan*i; //2
            lol = suanhan;
        }
        long long int fin = ans/lol;
        fin = fin*2;
        printf("%lld",fin);
    }


}
