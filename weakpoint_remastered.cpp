#include<bits/stdc++.h>
using namespace std;
const int X = 5e5+9;
int op,mx=-1,tomoriru=0;
int dp[X];
bool vst[X];
vector<int> v[X];

int solve(int n)
{
    int sum=0;
    bool cyc=false;
    vst[n] = true;
    for(auto it : v[n])
    {
        if(it==op) cyc=true;
        if(vst[it]) continue;
        int t=solve(it);
        if(t==-1) cyc=true;
        else sum+=t;
    }
    dp[n] = sum;
    if(cyc) return -1;
    return 1+sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> op;
    for(int o=0;o<n;++o)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    solve(op);
    for(int i=1;i<=n;++i) if(dp[i] > mx) mx=dp[i],tomoriru=i;
    cout << tomoriru << endl << mx;

}
