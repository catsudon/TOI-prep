#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
bool vst[15009];
vector<ll> dp(15009,LONG_MAX);
vector<int> ans;
int i=0,n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<pii> v(n);

    for(int i=0;i<n;++i)
    {
        int a,b; cin >> a >> b;
        v[i] = {a,b};
    }
    while(1)
    {
        ll mn = LONG_MAX;
        vst[i] = true;
        int memo = 20000;
        for(int j=0;j<n;++j)
        {
            if(vst[j]) continue;
            if(abs(v[i].f-v[j].f) + abs(v[i].s-v[j].s) < dp[j]) dp[j]=abs(v[i].f-v[j].f) + abs(v[i].s-v[j].s);
            if(dp[j] < mn)
            {
                mn = dp[j];
                memo = j;
            }
        }
        if(memo==20000) break;
        ans.emplace_back(mn);
        i = memo;
    }

    sort(ans.begin(),ans.end());
    ll fin = 0;
    for(int i=0;i<n-k;++i) fin=fin+ans[i];
    cout << fin;
}
