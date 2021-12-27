#include<iostream>
using namespace std;

int main()
{
    string s; cin >> s;
    int dec=0,coef=1;
    for(int i=s.length()-1;i>=0;--i)
    {
        dec+=(s[i]-48)*coef;
        coef*=2;
    }
    cout << dec;
}
