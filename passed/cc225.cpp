#include<bits/stdc++.h>
using namespace std;
int vst[200009];
int dp[200009]; // if == 0  = false
int  a[200009];
/*
    abstract

  1 2 3 1 2 7 8 2 3 1
  x x o
    x x o
      x x o
        x x x x x o
          x ----> x o

*/

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,q,cnt=0,p=1; cin >> n >> k >> q;
    for(int i=1;i<=n;++i) cin >> a[i]; a[0] = n+5;

    for(int i=1;i<=n;++i)
    {
        vst[a[i-1]]--;
        if(vst[a[i-1]] == 0 and a[i-1] <= k) cnt--;
        while(cnt != k and p<=n)
        {
            if(vst[a[p]] == 0 and a[p] <= k) cnt++;
            vst[a[p++]]++;
        }
        if(cnt==k) dp[i] = p-1;

   //     for(int i=1;i<=3;++i) cerr << vst[i] << " "; cerr << cnt << endl;

    }


   //  for(int i=1;i<=n;++i) cerr << dp[i] << " " ; cerr << endl;
    while(q--)
    {
        int l,r; cin >> l >> r;
        if(dp[l] <= r and dp[l]!=0) cout << "YES\n"; else cout << "NO\n";
    }
}
