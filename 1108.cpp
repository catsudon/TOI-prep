#include<bits/stdc++.h>
#define f first
#define s second
#define N 1e6+9
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
ll num[N],qs[N],dp[N];
ll mx=0;

int main()
{
    ll n,k;
    cin >> n >> k;

    for(int i=1;i<=n;++i)
    {
        cin >> num[i];
        qs[i] = qs[i-1] + num[i];
    }

    dequeue<pll> dq; // sum : pos

    dq.emplace(qs[1],1);

    for(int i=2;i<=n;++i)
    {
        while(!dq.empty() and qs[i] - qs[dq.front().s] > k) dq.pop_front();
        while(!dq.empty() and )
        dq.emplace_back(qs[i]+dq.top().f,i);
    }

    cout << mx;
}
