#include<iostream>
#include<iomanip>

using namespace std;

int main(){

float n,x;
cin >> n >> x;

for(int i=0;i<10;i++){
    n = n + (x/100)*n;
}

cout << fixed << setprecision(2) << n;


}
