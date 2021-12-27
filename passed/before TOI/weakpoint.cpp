#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;

int dp[N];
bool vst[N];
vector<int> v[N];
int op;

int dfs(int pos , int sum)
{
    vst[pos]=1;
    bool cyc=0;

    for(auto it : v[pos])
    {
        if(it==op) cyc=1;
        if(vst[it]) continue;

        int t = dfs(it,0);
        if(t==0) cyc=1;
        sum+=t;
    }

   // cerr << pos << ' ' << sum << endl;
    dp[pos]=sum;
    if(!cyc) return sum+1;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> op;
    for(int i=1;i<=n;++i)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(op,0);
    int mx=-1,memo=0;
    for(int i=1;i<=n;++i)
    {
        if(i==op) continue;
        if(dp[i] > mx) mx=dp[i],memo=i;
    }
    cout << memo << '\n' << mx;

}
