#include<iostream>

using namespace std;

int main(){

int sum=0;
int a;
for(int i=0;i<10;i++){
    cin >> a;
    sum +=a;
}

sum /=10;
cout << sum;


}
