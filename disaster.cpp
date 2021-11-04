#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pci = pair<char,int>;
bool vst[500]; /// vst edge
vector<pci> v[200];
vector<char> path; bool solved=0;
int e,n=0;

int dfs(char pos,int sum)
{
    if(solved) return 0;
    path.push_back(pos);
  //  cerr << pos << ":" << sum << " ";
    if(sum==e)
    {
        for(auto it : path) cout << it << " ";
        solved=1;
    }
    for(auto it : v[pos])
    {
        int pathID = it.s;
        char nodeV = it.f;
        if(vst[pathID]) continue;
        vst[pathID]=1;
        dfs(nodeV,sum+1);
        vst[pathID]=0;
    }


    path.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> e;
    int p=1;
    while(e--)
    {
        string a; cin >> a;
        for(auto it : a) if(!vst[it]) n++,vst[it]=true;
        v[a[0]].push_back({a[1],p});
        v[a[1]].push_back({a[0],p++});
    }
    p--; e=p;
    for(int i=1;i<=200;++i) vst[i]=0;///reuse, lol
    for(int i='Z';i>='A';--i)
    {
        if(!solved)
        dfs(char(i),0);
    }

}
