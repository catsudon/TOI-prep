#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[30001];
int parent[30001];
bool vst[30001];
vector<int> leaf;
int main()
{
    cin >> n >> m;
    for(int i=1;i<n;++i)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int c=0;
    for(int i=1;i<=n;++i)
    {
        if(v[i].size() == 1)
        {
            c++;
            leaf.emplace_back(i);
            parent[i] = v[i][0];
        }
    }
    cout << (c+1)/2 << endl;
   // cerr << "leaf : "; for(auto it : leaf ) cerr << it << ' ' ; cerr << endl;
    // match leaf with different parent
    int total_visit = 0;
    for(int i=0;i<leaf.size();++i)
    {
        if(vst[leaf[i]]) continue;
        for(int j=0;j<leaf.size();++j)
        {
            if(vst[leaf[i]]) continue;
            if(parent[leaf[i]] == parent[leaf[j]]) continue;
            vst[leaf[i]] = 1 , vst[leaf[j]]=1;
            cout << leaf[i] << ' ' << leaf[j] << endl;
        }
    }
    // match leaf with same parent
    vector<int> LEAF;
    for(auto it : leaf)
    {
        if(!vst[it]) LEAF.push_back(it);
    }

    bool o=0; int bef;
    if(LEAF.size()!=1)
    {
        for(auto it : LEAF)
        {
            if(o==1) cout << bef << ' ' << it << endl;
            o=!o; bef=it;
        }
        if(LEAF.size()%2==1)
        {
            cout << bef << ' ' ;
            int link;
            for(int i=1;i<=n;++i)
            {
                if(parent[bef] == i) continue;
                if(bef == i) continue;
                cout << i; return 0;
            }

        }
    }
    else
    {
        int link;
        for(int i=1;i<=n;++i)
        {
            if(parent[LEAF[0]] == i) continue;
            if(LEAF[0] == i) continue;
            link = i; break;
        }
        cout << link << ' ' << LEAF[0];

    }
}
