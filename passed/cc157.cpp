#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    ll pls , mul; pls=0 , mul=1;
    vector<ll> mns;
    int cnt=0;
    while(n--)
    {
        char op ; ll a ; cin >> op >> a;
        if(op == '-') mns.emplace_back(a);
        if(op == '+') pls+=a;
        if(op == 'x' and a!=0) mul*=a;
        else if(op=='x' and a==0) cnt++;
    }

  //  sort(mns.begin(),mns.end());
    ll msum = 0;
    if(!cnt)
    for(int i=0;i<mns.size()-cnt;++i)
    {
        msum+=mns[i];
    }

    cout << pls*mul-msum;
}
