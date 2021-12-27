#include<iostream>
#include<string>

using namespace std;

int main(){

string a;
cin >> a;
int numcount=0,alp=0,vowel=0;
cout << a.length() << endl;
for(int i=0;i<a.length();i++){
    if((int)a[i]-48>=0 && (int)a[i]-48<=9) numcount++;
    else if(a[i] == 'a' || a[i] == 'A' || a[i] == 'e' || a[i] == 'E' || a[i] == 'i' || a[i] == 'I' || a[i] == 'o' || a[i] == 'O' || a[i] == 'u' || a[i] == 'U')
    {

        vowel++;
        alp++;
    }
    else alp++;
}

cout << alp << endl << vowel;
}
