#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
bool vst[15009];
vector<ll> dp(15009,LONG_MAX);
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> nearest(n);
    pii v[n];
    for(int i=1;i<=n;++i)
    {
        ll a,b; cin >> a >> b;
        v[i] = {a,b};
        nearest[i] = INT_MAX;
    }
    vector<ll> pipe;
    int i=1;
    while(1)
    {
        ll mn = LONG_MAX;
        vst[i] = true;
        int memo = -1;
        for(int j=1;j<=n;++j)
        {
            if(vst[j]) continue;
         //   cerr << i << " " << j << endl;
            dp[j] = min(
                        dp[j]
                        ,abs(v[i].f-v[j].f) +
                        abs(v[i].s-v[j].s)
                        );
            if(dp[j] < mn)
            {
                mn = dp[j];
                memo = j;
            }
        }
     //   cerr << mn << i << " : " << memo << endl;
        if(memo==-1) break;
        pipe.emplace_back(mn);
        i = memo;
     //   p = i;
    }
    ll sum=0;
    sort(pipe.begin(),pipe.end());
    for(int i=0;i<n-k;++i)
    {
        sum+=pipe[i];
      //  cout << pipe[i] << ' ';
    }
    cout << sum;
}
