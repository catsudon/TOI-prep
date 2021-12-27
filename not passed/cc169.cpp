#include<bits/stdc++.h>
using namespace std;
int dp[100009];
int a[1000009],b[1000009];
vector<int> aa[100009];
int rr[1000009];
bool debug = 0; long long cnt=1;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m,mx=0; cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=m;++i) cin >> b[i];
    for(int i=1;i<=100000;++i) for(int j=i;j<=100000;j+=i) dp[j]++;
    for(int i=1;i<=n;++i) a[i] = dp[a[i]];
    for(int i=1;i<=m;++i) b[i] = dp[b[i]];
    for(int i=n;i>=1;--i)
    {
  //      cerr << a[i] << " " << i << endl;
        aa[a[i]].push_back(i);
    }

 //   for(int i=1;i<=n;++i) cerr << a[i] << " "; cerr << endl;
 //   for(int i=1;i<=m;++i) cerr << b[i] << " "; cerr << endl;

    bool ok = 0;
      for(auto it : aa[b[1]])
        {
            if(it>n-m+1) continue;
            rr[it] = 1;
            ok=1;
            mx=1;
        }
 //   for(int i=1;i<=20;++i) cerr << rr[i] << " "; cerr << endl;
    if(!ok)
    {cout << 0; return 0;}
      for(int i=2;i<=m;++i)
      {
        for(auto it : aa[b[i]])
        {
        //    cerr << cnt++ << " ";
            if(rr[it-1] != i-1 or it>n-m+i) continue;
            rr[it]=i;
            mx=i;
        }
     //   for(int k=1;k<=20;++k) cerr << rr[k] << " "; cerr << endl;
      }
       cout << mx;
}
