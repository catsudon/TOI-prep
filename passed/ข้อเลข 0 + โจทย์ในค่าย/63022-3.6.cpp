#include<iostream>

using namespace std;

int main(){

char a;
cin >> a;
int alp = (int)a;
if(alp>=96 && alp<=122){
    alp-=32;
}

for(int i=alp;i>64;i--){
    cout << (char)i << endl;
}



}
