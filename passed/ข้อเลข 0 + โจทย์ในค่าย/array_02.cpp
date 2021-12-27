#include<iostream>

using namespace std;

int main(){

int a[5];
int n;
cout << "Enter N : "
cin >> n;
for(int i=0;i<n;i++) cin >> a[i];
for(int i=n-1;i>=0;i--) cout << a[i] << " ";

}
