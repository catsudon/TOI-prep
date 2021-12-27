#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
vector<int> v[N];
short color[N];

int sol(int pos,int col,int p)
{
    int next = 1;
    if(col==1) next=2;
    color[pos] = col;
    for(auto it : v[pos])
    {
        if(it==p) continue;
        if(color[it] == next) continue;
        if(color[it] != next) /// how can this be true?
            {}
        if(color[it]==0) sol(it,next,pos);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; int e = n-1;
    while(e--)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i=1;i<=n;++i)
    {
        sort(v[i].begin(),v[i].end());
        if(v[i].empty()) continue; // this case is not gonna happend
        if(color[i] == 0) sol(i,1,-1);
    }

    int one=0,two=0;
    for(int i=1;i<=n;++i)
    {
        if(color[i] == 1) one++;
        else two++;

    //    cerr << color[i] << " ";
    }
  //  cerr << endl;
    long long ans = 0;
    for(int i=1;i<=n;++i)
    {
        int co;
        if(color[i] == 1) co = two; else co = one;
        for(auto it : v[i])
        {
            if(color[i] == color[it]) continue;
      //      cerr << i << " and " << it << " coef =  " << co << " color = " << color[i] << endl;
            co--;
        }
        ans+=co;
    }

    cout << ans/2;




}
