#include<iostream>

using namespace std;

int main(){

cout << "Enter a number : ";
int n;
cin >> n;
cout << endl;

for(int i=1;i<=n-1;i++){
    for(int j=n-i;j>0;j--){
        cout << " ";
    }
    cout << "*";
    for(int k=0;k<i-1;k++) cout << "-*";

    cout << endl;
}

for(int i=0;i<n;i++){
    for(int j=i;j>0;j--){
        cout << " ";
    }
    cout << "*";
    for(int k=0;k<n-i-1;k++) cout << "-*";

    cout << endl;
}


}
