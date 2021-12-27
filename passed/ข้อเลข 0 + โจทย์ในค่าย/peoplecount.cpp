#include<bits/stdc++.h>
using namespace std;

int main(){

int time[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int n;
scanf("%d",&n);
int a,b;
for(int k=0;k<n;++k){
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;++i) time[i]++;
}
int m=0;
int mem;
for(int i=0;i<24;++i){
   // printf("%d %d\n",time[i],m);
    if(time[i]>m){
        m=time[i];
    }
}
printf("%d",m);

}
