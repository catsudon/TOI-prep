#include<stdio.h>

int main(){

int m,n;
scanf("%d %d",&m,&n);
int l,k,lk;
scanf("%d %d",&l,&k);
lk = l*k;
int hito;
scanf("%d",&hito);
int lightprice = 0;
int jetprice = lk*hito;
int a;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        scanf("%d",&a);
        lightprice += a;
    }
  //  printf("\n");
}
int lol = jetprice+lightprice;
if(lol%hito==0){
    lol = lol/hito;
}else{
    lol = lol/hito +1;
}
printf("%d",lol);
}
