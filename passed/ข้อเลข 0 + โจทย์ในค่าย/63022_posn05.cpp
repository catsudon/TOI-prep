#include<iostream>

using namespace std;

int main(){

string a;
int key;
getline(cin,a);
cin >> key;
for(int i=0;i<a.length();i++){
    if(a[i]>=97 && a[i]<=122){
        int x = a[i]-96;
        x+=key;
        x%=27;
        if(x==0) x=1;
        cout << char(96+x);
    }
    else if(a[i]>=65 && a[i]<=90){
        int x = a[i]-64;
        x+=key;
        x%=27;
        if(x==0) x=1;
        cout << char(64+x);
    }
    else cout << a[i];
}

}
