#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    ll getto = 23*12+98;
    ll costPerSet = 7*12;
    ll buy = n/getto+1;
    ll buyAll = buy*costPerSet;
    ll kirei = getto * buy;
    ll mn = buyAll;
    cerr << "buy " << buy << " set\n" << "spend " << buyAll << endl;
    cerr << "got " << kirei << endl;
    for(int i=1;i<=12;++i)
    {
        ll newKirei = kirei - 23*i - 98;
        ll newcost = buyAll - 7*i;
      //  cerr << "got " << newKirei << " spending " << newcost << endl;
        if(newKirei < n) break;
        mn = min(mn,newcost);
    }
    cout << mn;
}
