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


int hex=0;
int l=1;
for(int i=4;i>=1;i--){
    if(bin[i]==1){
        hex+=l;
    }
    l*=2;
}

if(bin[0]==1) cout<<1;
switch(hex){

    case 10:
        cout << "A";
        break;
    case 11:
        cout << "B";
        break;
    case 12:
        cout << "C";
        break;
    case 13:
        cout << "D";
        break;
    case 14:
        cout << "E";
        break;
    case 15:
        cout << "F";
        break;
    default:
        cout << hex;


}



}
