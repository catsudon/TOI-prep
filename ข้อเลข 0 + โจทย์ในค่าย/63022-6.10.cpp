#include<iostream>
#include<string>

using namespace std;

int main(){

string a,b;
cout << "*******************************************" << endl;
cout << "Input String1 : "; cin >> a;
cout << "Input String2 : "; cin >> b;
cout << "*******************************************" << endl;
int min = a.length();
int max = a.length();
if(b.length()<min) min=b.length();
else max=b.length();

cout << "Result of Even Position               = ";
for(int i=0;i<min;i++){
    if(i*2<a.length()-1)cout << a[1+i*2];
    if(i*2<b.length()-1)cout << b[1+i*2];
}
cout << endl;
cout << "Result of Odd Position                = ";
for(int i=0;i<min;i++){
    if(i*2<a.length())cout << a[i*2];
    if(i*2<b.length())cout << b[i*2];
}
cout << endl << "Result of String 1&2          = ";
for(int i=0;i<max;i++){
    if(i<a.length())cout << a[i];
    if(i<b.length())cout << b[i];
}
cout << endl << "Result of Upper String 1&2    = ";
for(int i=0;i<a.length();i++){
    if(a[i]>=97 && a[i]<=122) cout << char(a[i]-32);
    else cout << a[i];
}
cout << " ";
for(int i=0;i<b.length();i++){
    if(b[i]>=97 && b[i]<=122) cout << char(b[i]-32);
    else cout << b[i];
}
cout << endl << "Result of Lower String 1&2    = ";
for(int i=0;i<a.length();i++){
    if(a[i]>=65 && a[i]<=90) cout << char(a[i]+32);
    else cout << a[i];
}
cout << " ";
for(int i=0;i<b.length();i++){
    if(b[i]>=65 && b[i]<=90) cout << char(b[i]+32);
    else cout << b[i];
}
cout << endl << "Result of Reverse String 1&2  = ";
for(int i=0;i<a.length();i++){
    if(a[i]>=65 && a[i]<=90) cout << char(a[i]+32);
    else if(a[i]>=97 && a[i]<=122) cout << char(a[i]-32);
    else cout << a[i];
}
cout << " ";
for(int i=0;i<b.length();i++){
    if(b[i]>=65 && b[i]<=90) cout << char(b[i]+32);
    else if(b[i]>=97 && b[i]<=122) cout << char(b[i]-32);
    else cout << a[i];
}
cout << endl << "*******************************************";




}
