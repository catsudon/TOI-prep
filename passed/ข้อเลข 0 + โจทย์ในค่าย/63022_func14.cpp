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
cout << "dice1 : " << a << endl;
int b = dice();
cout << "dice2 : " << b << endl;
int c = dice();
cout << "dice3 : " << c << endl;
int sum = a+b+c;
cout << "three : " << sum << endl;
if(sum>=4 && sum<=10) cout << "low" << endl;
if(sum>=11 && sum<=17) cout << "high" << endl;
if(a==b==c) cout << "three of a kind";


}
