#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

int ans=rand();
while(ans>100) ans/=10;
int n,x=0;
while(n!=ans){
    cout << "Enter number (1-100) : ";cin >> n;
    x++;
    if(n>ans) cout << "The number is too high, Try again.";
    else if(n<ans) cout << "The number is too low, Try again.";
}
cout << "Correct !!!";
if(x==1) cout << endl << "Exactly right.";


}
