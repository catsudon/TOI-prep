#include<stdio.h>
#include<math.h>

float x1,x2;

int main(){


int a,b,c;
scanf("%d %d %d",&a,&b,&c);

float coef = b*b - 4*a*c;

if(coef<0){
    printf("error");
    return 0;
}
else if((int)coef==0) {

    printf("x = %d",-b/(2*a));

}
else{

    x1 = ((-b + sqrt(coef)) /(2*a));
    x2 = ((-b - sqrt(coef)) /(2*a));

    printf("x = ");
    if((int)x2==x2) printf("%.0f",x2);
    else printf("%.2f",(x2));
    printf(", ");
    if((int)x1==x1) printf("%.0f",x1);
    else printf("%.2f",(x1));



}

}
