#include<stdio.h>



int half(int num){

    num = num/2;
    return num;

}

int main(){

    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int count =0;
    while(a!=1 || b!=1 || c!=1){
        if(a!=1){
        a = half(a);
     //   printf("A:%d\n",a);
        count++;
        }
        if(b!=1){
        b = half(b);
    //    printf("B:%d\n",b);
        count++;
        }
        if(c!=1){
        c = half(c);
     //   printf("C:%d\n",c);
        count++;
        }
    }
printf("%d",count);
}
