#include<stdio.h>


int main(){

int N,wannafind;
scanf("%d %d",&N,&wannafind);
int all[N-2];
int start = 2;
for(int i=0;i<N-1;i++){
    all[i]=start;
    start++;
}

int banged[N-2];
int bangcount=0;
for(int i=0;i<N-1;i++){
    int bangHUH=0;
    for(int j=0;j<bangcount;j++){
        if(all[i]==banged[j]){
            bangHUH=1;  //     printf("all[i]: %d \n banged[j]: %d\n",all[i],banged[j]);
        }
    }
    if(bangHUH==0){
        banged[bangcount]=all[i];
        bangcount++;
        for(int hoho=2;hoho<N/all[i]+1;hoho++){

        int bangHAH = 0;
            for(int j=0;j<bangcount;j++){
        if(all[i]==banged[j]){bangHAH=1;}
        }
            if(bangHAH==0){
                banged[bangcount] = hoho*all[i];
                bangcount++;
            }
        if(all[i]==wannafind){
            printf("%d",bangcount);
            break;
        }
    }
}
}





}
