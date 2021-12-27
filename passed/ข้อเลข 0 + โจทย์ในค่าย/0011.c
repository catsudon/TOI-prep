#include <stdio.h>



int main(){
    int number[10];
    int a,count=0;
    for(int i=0;i<10;i++){
        scanf("%d",&a);
        a = a%42;
        for(int j=0;j<i;j++){
            if(number[j]==a){
                count++;
                break;
            }
        }
        number[i]=a;

    }

    printf("%d",10-count);
}
