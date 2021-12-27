#include<iostream>

using namespace std;

int main(){

int w,n;
cin >> w >> n;
if(w>10000) cout << n*10000;
else if(w>2000) cout << n*3000;
else if(w>100) cout << n*1000;
else if(w>20) cout << n*500;
else cout << n*200;

}
