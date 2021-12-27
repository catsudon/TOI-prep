#include<iostream>
#include<string>

using namespace std;
string a;
void rev(){
    for(int i=a.length()-1;i>=0;i--) cout << a[i];
}

main(){
cin >> a;
rev();
}
