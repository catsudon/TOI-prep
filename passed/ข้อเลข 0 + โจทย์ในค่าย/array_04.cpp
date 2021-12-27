#include<iostream>

using namespace std;

int main(){

int a[20];
int sum=0;

for(int i=0;i<20;i++) {
    cin >> a[i];
    sum+=a[i];
}

cout << sum;

}
