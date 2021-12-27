#include<bits/stdc++.h>
using namespace std;
vector<int> v[10009];
vector<int> dp(10009,-1);
int chi,n,m;
int mx = 0;
int solve(int floor,int ki)
{
    if(ki < 0 or ki <= dp[floor]) return 0;
    mx=max(mx,floor); dp[floor]=ki;
    for(auto it : v[floor]) solve(it,ki-1);
}
int main()
{
    cin >> chi >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a,b; cin >> a >> b;
        v[a].push_back(b);
    }
    solve(1,chi); cout << mx;
}
