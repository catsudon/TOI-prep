#include<bits/stdc++.h>
using namespace std;
string codecube = "codecube";
int main()
{
    string a; cin >> a;
    int sum = 0;
    int p=0; // always % by 8
    int i=0;
    while(i<a.length())
    {
        if(a[i] == codecube[p])
        {
            i++; p++; p%=8;
            continue;
        }
        p++; sum++; p%=8; continue;
    }
    sum+=(8-p)%8;
    cout << sum;
}
