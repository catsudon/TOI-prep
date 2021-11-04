#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int legend = 9651;
unordered_map<ll,int> virus;
ll memo;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,m;
    cin >> k >> m;
    vector<ll> neko(k,0);
    for(int i=0;i<k;++i)
    {
        string a; cin >> a;
        ll lg = 1;
        for(int j=m-1;j>=0;--j)
        {
            neko[i]+=(int(a[j])-48)*lg;
            lg*=legend;
        }
        virus[neko[i]] = i+1;
    }
 // cout << endl << endl;  for( auto it : neko) cout << it << endl;
 // cout << endl << endl;
  int n; cin >> n;
  for(int i=0;i<n;++i)
  {
      set<int> vrs;
      int llenn; cin >> llenn;
      string a; cin >> a;
      ll lg = 1;
      ll checkthisnum = 0;
      for(int j=m-1;j>=0;--j)
      {
          checkthisnum+=(int(a[j])-48)*lg;
          if(j==0) memo = lg;
          lg*=legend;
      }
      if(virus[checkthisnum]!=NULL)
      {
          vrs.insert(virus[checkthisnum]);
      }
      for(int j=m;j<llenn;++j)
      {
          checkthisnum-=(int(a[(j-m)])-48)*memo;
          checkthisnum*=legend;
          checkthisnum+=(int(a[j])-48);
        //  cout << checkthisnum << "  ";
          if(virus[checkthisnum]!=NULL) vrs.insert(virus[checkthisnum]);
      }
      if(vrs.empty()) cout << "OK";
      else
      {
          for( auto it : vrs) cout << it << " ";
      }
      cout << "\n";
  }
}
