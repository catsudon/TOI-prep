#include<iostream>

using namespace std;

int main(){

string s;
char b;
int h,w,bw;
cout << "Input String        ==> ";cin >> s;
cout << "Height String       ==> ";cin >> h;
cout << "Width String        ==> ";cin >> w;
cout << "Border Character    ==> ";cin >> b;
cout << "Border Width        ==> ";cin >> bw;
cout << endl;
for(int i=0;i<bw;i++){
    for(int j=0;j<2*bw+w*s.length();j++) cout << b;
 cout << endl;
}

for(int i=0;i<h;i++){
    for(int j=0;j<bw;j++) cout << b;
    for(int k=0;k<w;k++) cout << s;
    for(int j=0;j<bw;j++) cout << b;
    cout << endl;

}

for(int i=0;i<bw;i++){
    for(int j=0;j<2*bw+w*s.length();j++) cout << b;
 cout << endl;
}




}
