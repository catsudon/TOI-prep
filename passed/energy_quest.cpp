#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ll = long long;
int op,ed,k,n,p=0,sz;
int cst1[100009],getto[100009];
vector<pii> v[100009];
bool foundK = 0,foundEd = 0,ok = 0;
bool vst[100009];
bool ispath[100009];
vector<int> op_k; /// store path
vector<int> k_ed; /// store path
vector<int> temp;
ll sum = 0;
int dfs1(int pos,int par)
{
    if(foundK) return 0;
    temp.push_back(pos);
    if(pos == k ) op_k = temp,foundK = 1;
    else
    {
        for(auto it : v[pos])
        {
            if(it.s == par) continue;
            dfs1(it.s,pos);
        }
    }
    temp.pop_back();
}

int dfs2(int pos,int par)
{
    if(foundEd) return 0;
    temp.push_back(pos);
    if(pos == ed) k_ed = temp,foundEd = 1;
    else
    {
        for(auto it : v[pos])
        {
            if(it.s == par) continue;
            dfs2(it.s,pos);
        }
    }
    temp.pop_back();
}

ll dfs3(int pos,ll summ)
{
    vst[pos] = true;
    if(ok)summ += (ll)getto[pos];
    else ok = 1;
  //  cerr << "DFS3 " << pos << " " << summ << endl;
    for(auto it : v[pos])
    {
        if(ispath[it.s] or vst[it.s]) continue;
        ll riru = dfs3(it.s,-it.f*2); /// node n path cost (go n back)
        summ += riru;
    }

    return max((ll)0,summ);
}

void dfs4(int pos)
{
    if(!vst[pos]) sum+=(ll)getto[pos];
    vst[pos] = 1;
  //  cerr << p << " " << sum << " " << op_k[p] << endl;
    p++;
    if(p == op_k.size()) return ;
    for(auto it : v[pos])
    {
        if(it.s == op_k[p])
        {
            sum-=it.f;
            dfs4(it.s);
        }
    }
}

void dfs5(int pos)
{
    if(!vst[pos]) sum+=(ll)getto[pos];
    vst[pos] = 1;
 //   cerr << p << " " << sum << " " << k_ed[p] << endl;
    p++;
    if(p >= k_ed.size()) return ;
    for(auto it : v[pos])
    {
        if(it.s == k_ed[p])
        {
            sum-=it.f;
            dfs5(it.s);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<n;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].emplace_back(c,b);
        v[b].emplace_back(c,a);
    }
    for(int i=1;i<=n;++i) cin >> getto[i];
    cin >> op >> ed >> k;
    dfs1(op,-1); //for(auto it : op_k) cerr << it << " "; cerr << endl;
    temp.clear();
    dfs2(k,-1); //for(auto it : k_ed) cerr << it << " "; cerr << endl;
    for(auto it : op_k) ispath[it] = 1;
    for(auto it : k_ed) ispath[it] = 1;
    for(auto it : op_k)
    {
        if(vst[it]) continue; ok=0;
        ll riru = dfs3(it,0);
       // cerr << it << ":" << riru << " ";
        sum+=riru;
    }
    for(auto it : k_ed)
    {
        if(vst[it]) continue; ok=0;
        ll riru = dfs3(it,0);
       // cerr << it << ":" << riru << " ";
        sum+=riru;
    }
  //  cerr << endl;
    p=0; for(int i=1;i<=n;++i) vst[i] = 0;
    dfs4(op_k[0]); /// what we got along the path
    p=0;
    dfs5(k_ed[0]);
    cout << sum;
}

/*
14
1 2 9
2 3 7
2 7 10
7 8 11
8 9 1
4 9 3
9 12 3
11 12 2
11 14 7
9 10 9
10 13 11
5 10 1
5 6 2
1 2 3 4 5 6 7 8 9 10 11 12 13 14
9 13 1

// -14
*/
