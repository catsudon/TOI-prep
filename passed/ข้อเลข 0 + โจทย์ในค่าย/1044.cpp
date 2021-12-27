#include<iostream>
using namespace std;

int n,m,mem1,mem2,idk=0;

main(){

cin >> n >> m;
int table[n][m];
int value[n][m];
int sum=0;
for(int i=0;i<n;i++) for(int j=0;j<m;j++) {cin >> table[i][j];sum+=table[i][j];}
for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> value[i][j];


for(int i=0;i<n;i++){
    int x=0,q=0;
for(int j=0;j<m;j++){
    if(i-1>=0) x+=value[i-1][j];
    q+=value[i][j];
    if(i+1<n)  x+=value[i+1][j];
}
if(x>q && x-q>idk) idk=x-q;
q=0;
x=0;
}



cout << sum+idk;

}
