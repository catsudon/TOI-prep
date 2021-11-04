#include<iostream>

using namespace std;


int main(){

int n[4][4];
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    cin >> n[i][j];

int sum=0;
for(int i=0;i<4;i++) sum+=n[i][i];
for(int i=3;i>=0;i--) sum+=n[i][3-i];
cout << sum;





}
