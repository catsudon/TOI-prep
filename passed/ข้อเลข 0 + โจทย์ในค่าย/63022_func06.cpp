#include<iostream>

using namespace std;
int n;

int fact(int n){

if(n==1) return 1;

return n*fact(n-1);

}
int main(){

cin >> n;
cout << fact(n);



}
