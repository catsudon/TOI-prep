#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

int n,i,max=-127,maxpos;
scanf("%d",&n);
int numlist[n];
for(i=0;i<n;i++){
    scanf("%d",&numlist[i]);
    if(numlist[i]>max) {
        max=numlist[i];
        maxpos = i;
    }

}
int bestright = max;
int bestrightpos = maxpos;
for(i=maxpos+1;i<n;i++){
    bestright += numlist[i];
    if(bestright>max) bestrightpos = i;
}
int bestleft = max;
int bestleftpos = maxpos;
for(i=maxpos-1;i>-1;i--){
    bestleft += numlist[i];
    if(bestleft>max) bestleftpos = i;
}
int sum=0;
int j=0;
for(i=bestleftpos;i<bestrightpos+1;i++){
    sum+=numlist[i];
}
if(sum>0){
    for(i=bestleftpos;i<bestrightpos+1;i++){
    printf("%d ",numlist[i]);
    }

    printf("\n%d\n",sum);
}
else{
    cout << "Empty sequence";
}


}
