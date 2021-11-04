#include <stdio.h>


int flag(int num){
    if (num==1){
        return 1;
    }
    return num*flag(num-1);

}

int main(){

int n;
scanf("%d",&n);
int sour[n];
int sour_count = 0;
int bitter[n];
int soursum=1,bittersum=0;

for(int i=0;i<n;i++){
    scanf("%d %d",&sour[i],&bitter[i]);
}
int ssum = 0,bsum = 0;
for(int i=1;i<n;i++){
    int s = flag(n)/(flag(i)*flag(n-i));
    ssum = ssum+s;
}
for(int i=1;i<n;i++){
    int b = flag(n)/(flag(i)*flag(n-i));
    bsum = bsum+b;
}
printf("the sample space is: %d",bsum);



}
