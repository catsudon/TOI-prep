#include<bits/stdc++.h>
using namespace std;
int n,e;
int to[100009];
int dp[100009];

int solve(int pos,int c)
{
    if(dp[pos] >= c) return 0;
   // cerr << pos << " " << c << endl;
    dp[pos] = c;
    c++;
    for(int i=pos+1;i<=to[pos];++i) solve(i,c);
}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        int a,b; cin >> a >> b;
        to[a] = max(to[a],b);
    }
    solve(1,1);
    int mx=0;
    for(int i=1;i<=100008;++i) mx = max(mx,dp[i]);
    cout << mx-1;
}
