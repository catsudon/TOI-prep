#include<iostream>

using namespace std;

int main(){

int base;
cin >> base;
base *=12;
if(base>=100000) cout << base*110/100;
else if(base>=70000) cout << base*107/100;
else if(base>=50000) cout << base*105/100;
else if(base>=30000) cout << base*103/100;
else cout << base*101/100;



}
