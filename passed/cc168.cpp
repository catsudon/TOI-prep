#include<bits/stdc++.h>
using namespace std;
const int sze = 1e5+9;
int c[sze];
int co[sze];
int cod[sze];
int code[sze];
int codec[sze];
int codecu[sze];
int codecub[sze];
int codecube[sze]; /// store begin

int main()
{
    string a; cin >> a; a = " " + a;
    int llenn = a.length();
    /// cst1
    for(int i=1;i<llenn;++i)
    {
        if(a[i] == 'c' ) c[i] = i;
    }
    /// co
    int memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(a[i] == 'c') memo = i;
        if(a[i] == 'o' and memo != -1) co[i] = memo;
    }
    /// cod
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(co[i]) memo = co[i];
        if(a[i] == 'd' and memo != -1) cod[i] = memo;
    }
    /// code
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(cod[i]) memo = cod[i];
        if(a[i] == 'e' and memo != -1) code[i] = memo;
    }
    /// codec
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(code[i]) memo = code[i];
        if(a[i] == 'c' and memo != -1) codec[i] = memo;
    }
    /// codecu
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(codec[i]) memo = codec[i];
        if(a[i] == 'u' and memo != -1) codecu[i] = memo;
    }
    /// codecub
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(codecu[i]) memo = codecu[i];
        if(a[i] == 'b' and memo != -1) codecub[i] = memo;
    }
    /// codecube
    memo = -1;
    for(int i=1;i<llenn;++i)
    {
        if(codecub[i]) memo = codecub[i];
        if(a[i] == 'e' and memo != -1) codecube[i] = memo;
    }
    int mn=696969;
    int tm,rr;
    for(int i=1;i<llenn;++i)
    {
        if(codecube[i]==0) continue;
        if(i-codecube[i] < mn)
        {
            mn = i-codecube[i];
            tm=i,rr=codecube[i];
        }
    }

    if(mn==696969) cout << -1;
    else cout << rr << " " << tm;
}
