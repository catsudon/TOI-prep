#include<iostream>

using namespace std;

int main(){

int n,w,h;
cin >> n >> w >> h;

for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cout << char(65+(i+j)%n);
    }
    cout << endl;
}



}
