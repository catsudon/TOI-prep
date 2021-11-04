#include<iostream>

using namespace std;

int main(){

char in[5];
char bin[5];
cout << "Enter binary : ";
for(int i=0;i<5;i++) {
    cin >> in[i];
}
for(int i=0;i<5;i++) {
    bin[i] = (int)in[i]-48;
}


int dec=0;
int l=1;
for(int i=4;i>=0;i--){
    if(bin[i]==1){
        dec+=l;
    }
    l*=2;
}

cout << dec;


}
