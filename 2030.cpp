#include<bits/stdc++.h>
using namespace std;
const int sze = 1e6+9;
int a[sze];
int dp[sze];
int dp2[sze];
long long ans=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r; cin >> n >> l >> r;
    for(int i=1;i<=n;++i) cin >> a[i];
    int rr=0; int mae = INT_MAX;
    for(int i=n;i>=1;--i)
    {
        if(mae > a[i]) rr=0;
        else rr++;
        dp[i] = rr,mae = a[i];
    }
    rr=0,mae=INT_MAX;
    for(int i=1;i<=n;++i)
    {
        if(mae > a[i]) rr=0;
        else rr++;
        dp2[i] = rr,mae = a[i];
    }

    for(int i=1;i<=n;++i) cerr << dp[i] << " "; cerr << endl;
    for(int i=1;i<=n;++i) cerr <<  a[i] << " "; cerr << endl;
    /// try every start point
    for(int op=1;op<=n;++op)
    {
        int ed=op+1;
        int past = 0;
        while(a[ed]-a[op] <=r and a[ed]-a[op] >=l and ed < n)
        {
            ed+=dp[ed];
            if(ed == past) break; past = ed;
            ed++;
        }
        ans+=ed+1-op;
        cerr << op << " " << ed << endl;
    }

    cout << ans;
}
