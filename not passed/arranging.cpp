#include<bits/stdc++.h>
using namespace std;
int n,k;
int mn = 90;
map<int,bool> mp;
vector<int> v;




void dfs(int lv , bool remo , int cnt , vector<int> a)
{
    if(cnt >= mn) return ;
    if(lv == v.size()) return ;
    if(remo)
    {
        for(int i=1;i<=n;++i) if(a[i] == v[lv]) a[i]=-1;
    }

    // check

    bool ok = 1;
    int p = 1;
    while(a[p]==-1) p++;
    int mae = a[p];
    for(int i=p+1;i<=n;++i)
    {
        if(a[i]==-1) continue;
        if(a[i] == mae) continue;
        if(a[i] != mae)
        {
            if(a[i] == -1) continue;
            if(mae  == -1) mae = a[i];
            else{ok=0; break;}
        }
    }
        for(int i=1;i<=n;++i) cerr << a[i] << ' ' ;cerr << endl;
   // cerr << lv << ' ' << cnt << ' ' << endl;
   // for(auto it : a) cerr << it << ' ' ;cerr << endl;
    if(ok)
    {
        mn = min(mn,cnt);
        return ;
    }

    dfs(lv+1,0,cnt,a);
    dfs(lv+1,1,cnt+1,a);


}

void riru(int rem,vector<int> a)
{

    if(rem!=900) a[rem]=-1;
    dfs(0,0,0,a);
    dfs(0,1,1,a);



}


void sol(vector<int> a)
{
    riru(900,a);
    for(int i=1;i<=n;++i)
    {
        if(a[i] == a[i-1] or a[i] == a[i+1]) continue;
        riru(i,a);
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<int> a(21),b(21);
    for(int i=1;i<=n;++i)
    {
        cin >>a[i];
        if(mp[a[i]]==true) continue;
        else
        {
            mp[a[i]]=true;
            v.push_back(a[i]);
        }
    }
    sort(v.begin(),v.end());
    for(auto it : v)  cerr << it << ' '; cerr << endl;

    sol(a);

    cout << mn;
}
