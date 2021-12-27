#include <iostream>

using namespace std;

int main(){

cout << "Enter : ";
int n;
cin >> n;
for(int i=1;i<=n;i++){
    for(int j=1;j<i;j++) cout << " ";
    cout << "\\";
    for(int j=(n-i)*2;j>0;j--){
        cout << " ";
    }
    cout << "/";


cout << endl;
}




}
