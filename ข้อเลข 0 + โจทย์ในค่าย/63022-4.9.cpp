#include <iostream>

using namespace std;

int main(){

cout << "Enter : ";
int n;
cin >> n;
for(int i=1;i<=n;i++){
    for(int j=0;j<n-i;j++) cout  << " ";
    for(int k=1;k<=i;k++) cout << k;
    for(int k=i-1;k>0;k--) cout << k;


cout << endl;
}




}
