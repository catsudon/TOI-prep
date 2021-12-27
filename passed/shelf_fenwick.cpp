#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e6+1;
int shelf[MXN+9];
int fenwick[MXN+9];

void appudeito(int i,int val)
{
    for(;i<=MXN;i+=i&-i) fenwick[i]+=val;
}

int query(int i)
{
    int sum=0;
    for(;i>0;i-=i&-i) sum+=fenwick[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n;
    for(int i=1;i<=n;++i) appudeito(i,1);
 //   for(int i=1;i<=16;++i) cerr << fenwick[i] << " ";
   // cerr << endl;
    for(int i=1;i<=n;++i) cin >> shelf[i];
    cin >> m;
    vector<int> v;
    while(m--)
    {
        int t; cin >> t;
        int idx = query(t);
        appudeito(t,1);
    //    for(int i=1;i<=16;++i) cerr << fenwick[i] << " ";
      //  cerr << endl;
        v.emplace_back(shelf[idx]);
    }
    for(auto it : v) cout << it << endl;
}
