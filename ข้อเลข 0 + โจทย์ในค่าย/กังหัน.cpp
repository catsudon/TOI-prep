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
        for(int j=0;j<1+(n-i);j++){
            cout << ' ';
        }
    }
    cout << ' ';



    cout << endl;
}



}
