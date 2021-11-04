#include<stdio.h>

int main(){

char a[90000],w;

scanf("%s %c",a,&w);

int pos=0;
int memo=0;

while(a[pos]!='/0'){
    if(w==a[pos]){
        memo = pos+1;
        break;
    }
    pos++;
}

printf("%d",memo);





}
