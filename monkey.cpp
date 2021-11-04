#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
bool use = false;
map<pair<pii,bool>,bool> vst;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,n,k;
    cin >> m >> n >> k;
    int mx = -1;

    int banana[n];
    vector<pii> v[n];
    for(int i=0;i<n;++i) cin >> banana[i];
    for(int i=0;i<k;++i)
    {
        int a,b; cin >> a >> b;
        v[a].push_back({b,1});
        v[a+1].push_back({b,-1});
    }

    for(int i=0;i<n;++i) sort(v[i].begin(),v[i].end());

    int op; cin >> op; op--;


    queue<pair<pii,bool> > q;   // pillar : level : used ?
    q.push({{op,0},false});

    while(!q.empty())
    {
        int pillar = q.front().f.f;
        int lv     = q.front().f.s;
        bool used  = q.front().s;
        q.pop();
        if(vst[{{pillar,lv},used}] == true) continue;

        vst[{{pillar,lv},used}] = true;

        auto it = upper_bound(v[pillar].begin(),v[pillar].end(),lv);

      //  if(it == )
    }




    cout << mx;
    if(use) cout << endl << "USE";
    else cout << endl << "NO";
}
