/*
TASK: Gift.cpp
LANG: C++
AUTHOR: Sathana Laolugsanalerd
ID: 63022
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll stsum=0,ndsum=0,rdsum=0;
int main()
{
    int k,n; cin >> k >> n;
    vector<ll> g;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        g.push_back(a);
    }
    sort(g.begin(),g.end());
  //  for(auto it : g) cerr << it << " ";
   vector<ll> st;
   for(int i=1;i<n;i+=2)
   {
       st.push_back(abs(g[i]-g[i-1]));
   }
   sort(st.begin(),st.end());
 //  for(auto it : st) cerr << it << " ";
   for(int i=0;i<k;++i) stsum += st[i];

   vector<ll> nd;
   g.push_back(g[0]);
   for(int i=2;i<=n;i+=2)
   {
       nd.push_back(abs(g[i]-g[i-1]));
   }
   sort(nd.begin(),nd.end());
  // cerr << endl;
  // for(auto it : nd) cerr << it << " ";
   for(int i=0;i<k;++i) ndsum += nd[i];


   cout << min(stsum,ndsum);
}
