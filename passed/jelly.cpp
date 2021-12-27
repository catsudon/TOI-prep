#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c; cin >> a >> b >> c;
    int cnt=0;
    while(a!=1)
    {
        a/=2;
        cnt++;
    }
    while(b!=1)
    {
        b/=2; cnt++;
    }
    while(c!=1)
    {
        cnt++; c/=2;
    }
    cout << cnt;
}
