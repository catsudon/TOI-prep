#include<stdio.h>




int bangcheck(int banged[],int num,int bangcount){
    for(int j=0;j<bangcount;j++){
        if(banged[j]==num){
            return 1;
        }
    }
    return 0;


}




int main(){

int n,wannafind;
scanf("%d %d",&n,&wannafind);
int all[n-2];
int start=2;
for(int i=0;i<n-1;i++){
all[i]=start;
start++;
}
int banged[n-2];
int bangcount=0;

for(int i=0;i<n;i++){
       int bangHUH = bangcheck(banged,all[i],bangcount);
        if(bangHUH==0){
            banged[bangcount]=all[i];
            bangcount++;
            if(all[i]==wannafind){
                printf("%d",bangcount);
                break;
                        }
        // then we have to bang all polynomials
                for(int y=2;y*all[i]<n+1;y++){
                    int bangHUHHUH = bangcheck(banged,all[i]*y,bangcount);
              //      printf("%d\n",all[i]*y);
                    if(bangHUHHUH==0){
                        banged[bangcount] = all[i]*y;
                        bangcount++;
                        if(all[i]*y==wannafind){
                            printf("%d",bangcount);
                            break;
                        }
                    }
                }

        }

}
/*for(int i=0;i<n-1;i++){
    printf("%d\n",banged[i]);
}*/
}

