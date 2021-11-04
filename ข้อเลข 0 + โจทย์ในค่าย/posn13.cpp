#include<iostream>

using namespace std;

int main(){

int direction,l;
cin >> direction >> l;

if(direction==1){
    for(int i=0;i<l;i++){
        for(int j=0;j<l-i;j++) cout << " ";
        cout << "/";
        cout << endl;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<=i;j++) cout << " ";
        cout << "\\";
        cout << endl;
    }
}
else{
    for(int i=0;i<l;i++){
        for(int j=0;j<=i;j++) cout << " ";
        cout << "\\";
        cout << endl;
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<l-i;j++) cout << " ";
        cout << "/";
        cout << endl;
    }
}



}
