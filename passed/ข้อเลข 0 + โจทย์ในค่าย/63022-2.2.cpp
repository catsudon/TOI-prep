#include<iostream>

using namespace std;

int main(){

int n=5;
int num;
int even=0,odd=0;
for(int i=0;i<n;i++){
    cin >> num;
    num%2==1 ? odd++  :even++;
}


cout << even << " " << odd ;

}
