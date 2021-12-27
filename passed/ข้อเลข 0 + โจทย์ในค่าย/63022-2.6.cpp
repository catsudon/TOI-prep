#include<iostream>

using namespace std;

int main(){

char a;
cin >> a;
//cout << (int)a << endl;
int ascii = (int)a;
if(ascii>=97 && ascii<=122){
    cout << char(ascii-32);
}
else if(ascii>=65 && ascii<=90){
    cout << char(ascii+32);
}
else cout << "error";




}
