#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;

// upper half
for(int i=1;i<=n;i++){
    for(int j=0;j<i;j++){
        cout << ' ';
    }
    cout << i;
    if(i!=n){
        for(int j=0;j<(n-i)+(n-i)-1;j++){
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;
}
// lower half
for(int i=n;i>0;i--){
    for(int j=0;j<i;j++){
        cout << ' ';
    }
    cout << i;
    if(i!=n){
        for(int j=0;j<(n-i)+(n-i)-1;j++){
            cout << ' ';
        }
        cout << i;
    }
    cout << endl;
}


}
