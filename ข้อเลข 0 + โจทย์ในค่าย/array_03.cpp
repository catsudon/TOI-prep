#include<iostream>

using namespace std;

int main(){

int a[20];
int count=0;

for(int i=0;i<20;i++) cin >> a[i];
for(int i=19;i>=0;i--) if(a[i]>0) count++;

cout << count;

}
