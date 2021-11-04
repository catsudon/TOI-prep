#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> t; /// cost : val
vector<int> v;
int a[20];
int chg; // ngern torn
bool ok = true;
int mainnum=-1,maincost=-1;

vector<int> solve(int n)
{
    vector<int> vv;
    while(n >= t[0].f)
    {
        n-=t[0].f;
        vv.push_back(t[0].s);
        mainnum = t[0].s;
        maincost = t[0].f;
     //   cerr << mainnum << " " << maincost << endl;
    }
    chg = n;
    return vv;
}

void solve2()
{
   // sort(v.begin(),v.end());
   int change = chg + maincost;
   int mx = -1; ok = 0;
   for(int i=mainnum+1;i<10;++i)
   {
       if(a[i] > change) continue;
       mx = i;
   }
   if(mx == -1) return ;
   change-=a[mx];
   chg = change;
   for(int i=0;i<v.size();++i)
   {
       if(v[i] == mainnum)
       {
           v[i] = mx; ok = 1;
           break;
       }
   }
   return ;
}

int main()
{
    int riru; cin >> riru;
    for(int i=0;i<10;++i) cin >> a[i];
    for(int i=0;i<10;++i) t.push_back({a[i],-i});

    sort(t.begin(),t.end()); for(int i=0;i<10;++i) t[i].s = -t[i].s;
  //  for(int i=0;i<10;++i) cerr << t[i].f << " " << t[i].s << endl;

    chg = 0;
    v = solve(riru);

    if(mainnum == -1 or v.empty()) {cout << -1; return 0;}

    ok = 1;
    while(ok)
    {
      //  v = solve2(v);
      solve2();
    }

    sort(v.begin(),v.end());
    if(v[v.size()-1] != 0)
    {
        if(v.size()==0) cout << -1;
        else for(int i=v.size()-1;i>=0;--i) cout << v[i];
    }
    else
    {
      //  cerr << "chg = " << chg << endl ;
    //    for(auto it : v) cerr << it << " "; cerr << endl;
        /// here we gotta find least 0 to pull out, which return biggest num
        int n = a[0];
        vector<pair<int,int> > wtf;
        for(int i=1;i<10;++i)
        {
            int temp = a[i]/n;
            if(a[i]%n) temp++;
            if(temp <= v.size()) wtf.push_back({temp,-i});
        }
        sort(wtf.begin(),wtf.end());
        if(wtf.empty()) cout << -1;
        else
        {
            cout << -wtf[0].s;
            for(int i=0;i<v.size() - wtf[0].f;++i) cout << 0;
        }

    }

}
