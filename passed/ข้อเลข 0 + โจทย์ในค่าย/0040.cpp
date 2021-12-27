#include<iostream>

using namespace std;

int main(){

int n;
string a;
cin >> n;
for(int i=0;i<n;i++){
    cin >> a;
    if((int(a[a.length()-1])-48)==2 && a.length()==1) cout << "T" << endl;
    else if((int(a[a.length()-1])-48)%2==1) cout << "T" << endl;
    else cout << "F" << endl;
}



}
