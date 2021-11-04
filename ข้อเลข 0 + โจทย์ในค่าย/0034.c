#include<stdio.h>


int main(){

    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    int i,j,k;
    int a,b,c,d;
    int daimai = 0;

    if(B>0 && C>0){
        k=0;
    }
    else if(B>0 && C<0){
        k=1;
    }
    else if(B<0 && C>0){
        k=2;
    }
    else if(B<0 && C<0){
        k=3;
    }



    for(i=1;i<C+1;i++){
        if(C%i==0){
            b=i;
            d=C/i;
            for(j=1;j<A+1;j++){
                if(A%j==0){
                    a=j;
                    c=A/j;


                    if(k==0){
                        int num = a*d + b*c;
                       // printf("FROM a=%d b=%d c=%d d=%d num=%d\n",a,b,c,d,num);
                        if(num==B){
                            daimai = 1;
                            printf("%d %d %d %d",a,b,c,d);
                            break;
                        }
                    }
                    if(k==1){
                        int num = a*d + -1*b*c;
                        if(num==B){
                            daimai = 1;
                            printf("%d %d %d -%d",a,b,c,d);
                            break;
                        }
                    }
                    if(k==2){
                        int num = -1*a*d + -1*b*c;
                      //  printf("%d %d %d %d\n",a,b,c,d);
                        if(num==B){
                            daimai = 1;
                            printf("%d -%d %d -%d",a,b,c,d);
                            break;
                        }
                    }
                    if(k==3){
                        int num = -1*a*d + b*c;
                      //  printf("FROM a=%d b=%d c=%d d=%d num=%d\n",a,b,c,d,num);
                        if(num==B){
                            daimai = 1;
                            printf("%d -%d %d %d",a,b,c,d);
                            break;
                        }
                    }
                    if(daimai==1){
                        break;
                    }


                }

        }
        if(daimai==1){
            break;
                    }

    }

    }
if(daimai==0){
    printf("No Solution");
}
}
