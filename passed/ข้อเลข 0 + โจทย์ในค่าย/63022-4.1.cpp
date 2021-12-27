#include<iostream>

using namespace std;

int main(){

int n;
cout << "Enter a positive number : ";
cin >> n;
int sum = 1;
for(int i=2;i<n;i++) {
    sum*=i;
    cout << i << " x ";
}
sum*=n;
cout << n << " = " << sum;




}
