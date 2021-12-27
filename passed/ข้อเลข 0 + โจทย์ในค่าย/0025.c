#include<stdio.h>

int i,j,k,l;

int main(){

long long int a,b;
char whattodo[1];
scanf("%lld",&a);
scanf("%s",&whattodo);
scanf("%lld",&b);



if(whattodo[0]=='+'){
    int countA = 0, countB = 0;
    int countforoneA[100],countforoneB[100];
    while(a>0){
        if(a%10==1){
            countforoneA[countA] = 1;
        }
        else if(a%10==0){
            countforoneA[countA] = 0;
        }
        a = a/10;
        countA++;
             //   printf("countA:%d\n",countA);
    }
    while(b>0){
        if(b%10==1){
            countforoneB[countB] = 1;
        }
        else if(b%10==0){
            countforoneB[countB] = 0;
        }
        b = b/10;
        countB++;
    }
 //   printf("%d %d",countA,countB);
    int max = countA;
    if(countB>max) max = countB;
    for(i=max-1;i>-1;i--){
        if(i<countA && i<countB){
            printf("%d",countforoneA[i]+countforoneB[i]);
                        //printf("passed this %d\n",i);
        }
        else if(i>=countA && i<countB){
            printf("%d",countforoneB[i]);

        }
        else if(i<countA && i>=countB){
            printf("%d",countforoneA[i]);
        }
    }

}
else{
    int countA = 0, countB = 0;
    int countforoneA[100],countforoneB[100];
    while(a>0){
        if(a%10==1){
            countforoneA[countA] = 1;
        }
        else if(a%10==0){
            countforoneA[countA] = 0;
        }
        a = a/10;
        countA++;
    }
    while(b>0){
        if(b%10==1){
            countforoneB[countB] = 1;
        }
        else if(b%10==0){
            countforoneB[countB] = 0;
        }
        b = b/10;
        countB++;
    }
    printf("1");
    for(i=0;i<countA+countB-2;i++){
        printf("0");
    }
    }
}

