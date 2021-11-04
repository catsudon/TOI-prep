#include<stdio.h>

int num[2510];

int main(){

    int n,max=-1<<20,from,to,str,end;

    int chp=1,chk=1,sum=0,i;

    scanf("%d",&n);

    for(i=0;i<n;i++){

        scanf("%d",&num[i]);

        if(sum+num[i]>=0){

            chp=0,sum+=num[i],to=i;

            if(chk) chk=0,from=i;

            if(max<sum)

                max=sum,str=from,end=to;

        }

        else    sum=0,chk=1;

    }

    if(chp) printf("Empty sequence\n");

    else{

        for(i=str;i<=end;i++)

            printf("%d ",num[i]);

        printf("\n%d\n",max);

    }

    return 0;

}
