#include<iostream>
#include<string>

using namespace std;

int main(){

int A=0,E=0,I=0,O=0,U=0;
string a;
cout << "Input String1    ==> ";
getline(cin,a);
cout << "Length of String ==> " << a.length() << " Characters" << endl;
cout << "Reverse String   ==> ";
for(int i=a.length()-1;i>=0;i--) {
    cout << a[i];
    if(a[i]>=97 && a[i]<=122) a[i]-=32;
    if(a[i]=='A') A++;
    if(a[i]=='E') E++;
    if(a[i]=='I') I++;
    if(a[i]=='O') O++;
    if(a[i]=='U') U++;
    }
cout << endl;
cout << "Upper String     ==> ";
for(int i=0;i<a.length();i++) cout << a[i];
cout << endl << "=-=-=-=-=-=-=-=-=-=" << endl << "Number of vowel" << endl << "=-=-=-=-=-=-=-=-=-=" << endl;
cout << "A or a = " << A << endl;
cout << "E or e = " << E << endl;
cout << "I or i = " << I << endl;
cout << "O or o = " << O << endl;
cout << "U or u = " << U << endl << "=-=-=-=-=-=-=-=-=-=";





}
