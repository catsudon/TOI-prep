#include<iostream>
#include<string>
using namespace std;

int main(){

string a;
int w,h;
cin >> a >> w >> h;
int len = a.length();

for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
        cout << a[(i+j)%len];
    }
    cout << endl;
}

}
