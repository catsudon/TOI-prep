#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dice(){
int x = rand()%6;
if(x==0) x==6;
return  x;
}

int main(){

int a = dice();
cout << "dice : " << a << endl;
if(a>=1 && a<=3) cout << "low";
else cout << "high";


}
