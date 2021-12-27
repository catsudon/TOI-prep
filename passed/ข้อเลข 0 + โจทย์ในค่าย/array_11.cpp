#include<iostream>

using namespace std;

int main(){

int n[5];
for(int i=0;i<5;i++) cin >> n[i];

for(int i=0;i<5;i++){
    cout << n[i] << "  ";
    for(int j=n[i];j>0;j--) cout << "*";
    cout << endl;
}




}
