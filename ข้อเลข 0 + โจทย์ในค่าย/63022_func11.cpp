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
}
cout << "You guessed " << x-1 << " times wrong.";


}
