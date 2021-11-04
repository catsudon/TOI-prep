#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,int>;
vector<int> jailed;
vector<int> temp;
vector<ppp> v[1009]; // goto : get :: egdeIdx
int dp1[1009];
int Free[1009];
int mx = 0;

int dfs(int time, int sum , int id)
{
    // go and stay


    if(id!=-1) temp.push_back(id);
    int coef = time;
    if(v[coef].size()==0) coef = Free[coef];

    int nexttime = Free[time];

    // no more way to go


 //   cerr << time << ' ' << sum << ' ' << id << ' ' << v[coef].size() <<  endl;

    if(coef == 0) if(sum > mx) mx=sum,jailed = temp; else;
    else
    for(auto it : v[coef])
    {
        int get = it.f.f;
        int go  = it.f.s;
        int idx = it.s;

        cerr << get << ' ' << go << ' ' << idx << endl;

        // go
        if(dp1[go] < sum+get) dfs(go,sum+get,idx);
    }

    if(nexttime != 0 and dp1[nexttime] < sum) dfs(nexttime,sum,-1);

    if(id!=-1) temp.pop_back();
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n; cin >> n;

    for(int i=1;i<=n;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({{c,b},i});
    }
    int bef = -1;
    for(int i=1000;i>=1;--i)
    {dp1[i]  = -1;
        if(v[i].size()==0) continue;
        Free[i] = bef;
        bef = i;
    }

    Free[0] = bef;

    dfs(0,0,-1);

    for(auto it : jailed) cerr << it << ' ';
}
