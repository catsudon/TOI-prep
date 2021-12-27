#include<bits/stdc++.h>
using namespace std;
const int big = 1e6+9;
int dp[100009];
int a[big],b[big];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=100000;++i) for(int j=i;j<=100000;j+=i) dp[j]++;
    int n,m,mx=0; cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        int t; cin >> t;
        a[i] = dp[t];
    }
    for(int i=1;i<=m;++i)
    {
        int t; cin >> t;
        b[i] = dp[t];
    }

  //  for(int i=0;i<n;++i) cerr << a[i] << " "; cerr << endl;
  //  for(int i=0;i<m;++i) cerr << b[i] << " "; cerr << endl;

    /// make a check point in O(M)
    int p=1;
    vector<int> warp(big,1);
    for(int i=2;i<=m;++i)
    {
        if(b[i] == b[warp[i-1]]) warp[i] = warp[i-1]+1;
    }
    for(int i=1;i<=m;++i) cerr << warp[i] << " "; cerr << endl;


    /// do KMP
    p=1; /// this points to b
    for(int i=1;i<=n and p<=m;++i)
    {
        if(i > n-m+1+p) break;
        if(a[i] == b[p]) p++;
        else p = warp[p-1];

        mx = max(mx,p-1);
    }

    cout << mx;
}
