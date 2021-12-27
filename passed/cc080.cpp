#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll legend = 98765431;
string a;

bool sol(int llenn , int len)
{
    bool ok = 1;
    ll chk = 0;
    ll sum = 0;
    ll memo = 1;
    for(int i=1;i<=len;++i)
    {
        chk*=legend;
        chk+=a[i];
    }

    for(int i=len+1;i<=llenn and ok;++i)
    {
        sum*=legend;
        sum+=a[i];
        if(i%len == 0)
        {
            if(sum!=chk) ok = 0;
            sum = 0;
        }
    }

    return ok;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q=5;
    while(q--)
    {
        cin >> a; a = " "+a;
        int cnt=0;
        int llenn = a.length()-1;
        for(int i=1;i<=llenn;++i)
        {
            if(llenn%i!=0) continue;
            if(sol(llenn,i)) cnt++;
        }
        cout << cnt << '\n';
    }
}
