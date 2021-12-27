#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;

int a[n],b[n],c[n],d[n],e[n];
int i=0;
float pound=0;
for(i=0;i<n;i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
    pound+=a[i];
    pound+=b[i]*0.75;
    pound+=c[i]*0.5;
    pound+=d[i]*0.25;
    pound+=e[i]*0.125;
}

if(pound>(int)pound){
int a = pound;
a++;
cout << a;
}
else{
cout << (int)pound;
}




}

