#include<bits/stdc++.h>
using namespace std;
int m,s,t,x=1;
int route[105][45];
vector<int> v;
int start(int n,int s,int coef)
{
    v.emplace_back(coef);
   // for(auto it : v) cout << it << " ";
    //cout << "\n";
    if(x==0) return 0;
    if(n==t && x)
    {
        for(auto it : v) cout << it << "\n";
        x=0;
        return 0;
    }
    if(route[n+1][s-1]==0) start(n+1,s-1,1);
    if(route[n+1][s]==0)   start(n+1,s,3);
    if(route[n+1][s+1]==0) start(n+1,s+1,2);
    v.pop_back();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> s >> t;
    for(int i=1;i<=t;++i) for(int j=1;j<=m;++j) cin >> route[i][j];
    vector<int> v;

    for(int i=0;i<=t;++i)
    {
        route[i][0]=1;
        route[i][m+1]=1;
    }
    for(int i=0;i<=m;++i)
    {
        route[t+1][i]=1;
    }

    if(route[1][s-1]==0)start(1,s-1,1);
    start(1,s,3);
    if(route[1][s+1]==0)start(1,s+1,2);
}
