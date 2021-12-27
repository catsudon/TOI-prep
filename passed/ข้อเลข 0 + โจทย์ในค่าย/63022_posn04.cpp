#include<iostream>

using namespace std;

int main(){

string a;
getline(cin,a);
for(int i=0;i<a.length();i++){
    if(a[i]==a[i+1]) continue;
    else cout << a[i];
}

}
