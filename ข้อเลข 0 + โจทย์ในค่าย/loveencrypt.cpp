#include<iostream>


using namespace std;

int main(){

int key;
string inp;
getline(cin,inp);
cin >> key;

for(int i=0;i<inp.length();i++){
    int enc = (int(inp[i]));
    if(inp[i]!=' '){
    enc = enc-64+key;
    enc %=27;
    enc+=64;
    if(enc==64) enc++;
    }
    cout << char(enc);
}



}
