#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6+9;
const ll legend = 97765431;
int mx=0;
ll bik[N];
ll smol[N];
ll dp[N];
ll a[N];
ll b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;

    for(int i=1;i<=n;++i) cin >> bik[i];
    for(int i=1;i<=m;++i) cin >> smol[i];

    for(int i=2;i<=100000;++i) for(int j=i;j<=100000;j+=i) dp[j]++;

    for(int i=1;i<=n;++i) a[i] = dp[bik[i]];
    for(int i=1;i<=n;++i) b[i] = dp[smol[i]];

    int l = 1 , r = m;
    while(l<=r)
    {
        int mid = (l+r)/2;
        ll check = 0 , memo = 1;
        for(int i=1;i<=mid;++i)
        {
            if(i!=1) memo*=legend;
            check*=legend;
            check+=b[i];
        }

        bool match = 0;
        ll sum = 0;
        for(int i=1;i<=mid;++i)
        {
            sum*=legend;
            sum+=a[i];
        }
        if(sum==check) match=1;

        for(int i=mid+1;i<=n and !match;++i)
        {
            sum -= memo*a[i-mid];
            sum *= legend;
            sum += a[i];
            if(sum == check) match=1;
        }

        if(match) l=mid+1 , mx = mid;
        else r=mid-1;

    }
    cout << mx;



}
