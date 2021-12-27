#include<iostream>
#include<string>

using namespace std;

int main(){


string n[4];
int len[4];
for(int i=0;i<4;i++) {
    cout << "Enter text" << i+1 << ":";
    cin >>n[i];
    len[i] = n[i].length();
}

for(int i=0;i<4;i++){
    cout << n[i] << ": " << len[i] << endl;
}



}
