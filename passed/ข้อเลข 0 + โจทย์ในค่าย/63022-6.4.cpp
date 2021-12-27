#include<iostream>

using namespace std;

int main(){

char a[17] = {'x','-','x','x','x','x','-','x','x','x','x','x','-','x','x','-','x'};

string n;
cin >> n;
int x=0;
for(int i=0;i<13;i++){
    if(a[i+x]=='x'){
        a[i+x] = n[i];
    }
    else if(a[i+x]=='-'){
        x++;
        a[i+x] = n[i];
    }
}

for(int i=0;i<17;i++) cout << a[i];






}
