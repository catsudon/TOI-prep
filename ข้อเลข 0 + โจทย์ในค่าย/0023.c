#include<stdio.h>


int main(){

int day,month,passedmonth=0;
scanf("%d %d",&day,&month);

switch(month){


case 12:
    passedmonth += 30;
case 11:
    passedmonth += 31;
case 10:
    passedmonth += 30;
case 9:
    passedmonth += 31;
case 8:
    passedmonth += 31;
case 7:
    passedmonth += 30;
case 6:
    passedmonth += 31;
case 5:
    passedmonth += 30;
case 4:
    passedmonth += 31;
case 3:
    passedmonth += 28;
case 2:
    passedmonth += 31;
case 1:
    passedmonth += 0;

}
int dayname = passedmonth+day;
dayname = dayname%7;
if(dayname==1){printf("Thursday");}
if(dayname==2){printf("Friday");}
if(dayname==3){printf("Saturday");}
if(dayname==4){printf("Sunday");}
if(dayname==5){printf("Monday");}
if(dayname==6){printf("Tuesday");}
if(dayname==0){printf("Wednesday");}

}
