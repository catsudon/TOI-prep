#include<iostream>

using namespace std;

int main(){

cout << "Enter a number : ";
int n;
cin >> n;


for(int big = 1; big <=n;big++){
for(int i=1;i<=big;i++){
    cout << "*";
}
for(int j=0;j<(n-big)*2;j++) cout << " ";
for(int i=1;i<=big;i++){
    cout << "*";
}
cout << endl;
}


for(int big  = n-1;big>0;big--){
    for(int i=big;i>0;i--) cout << "*";
    for(int j=(n-big)*2;j>0;j--) cout << " ";
    for(int i=big;i>0;i--) cout << "*";
    cout << endl;
}
}
