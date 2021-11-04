#include<stdio.h>



int main(){

int n,wannafind;
scanf("%d %d",&n,&wannafind);
int all[n];
int start=2;
for(int i=0;i<n-1;i++){
all[i]=start;
start++;
}
int banged[n];
int bangcount=0;

for(int i=0;i<n;i++){
       int bangHUH = 0;
       for(int j=0;j<bangcount;j++){
        if(banged[j]==all[i]){
            bangHUH = 1;
        }
       }
        if(bangHUH==0){
            banged[bangcount]=all[i];
            bangcount++;
            if(bangcount==wannafind) break;
        // then we have to bang all polynomials
        int lol = (n/all[i])+1;
            for(int y=2;y<lol;y++){
                    int bangHUHHUH = 0;
                    if(all[i]==2){}
                    else{
                        for(int j=0;j<bangcount;j++){
                        if(banged[j]==all[i]*y){
                            bangHUHHUH = 1;
                          //  printf("%d %d \n",all[i]*y,banged[j]);
        }
       }
                    }

                    if(bangHUHHUH==0){
                        banged[bangcount] = all[i]*y;
                        bangcount++;
                        if(bangcount==wannafind) break;
                    }
                }

        }

}

printf("%d",banged[wannafind-1]);
}

