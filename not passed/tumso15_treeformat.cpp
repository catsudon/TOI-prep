#include<bits/stdc++.h>
using namespace std;

vector<int> v[20];
int n;
int ans[20];
int vst[20];
int deg[20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=1;i<n;++i)
        {
            int a,b; cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
            deg[a]++; deg[b]++;
        }
        queue<pair<int,int> > q; // idx : parent
        for(int i=1;i<=n;++i)
        {
            if(deg[i]==1) q.push({i,0});
            deg[i]=0; vst[i]=0; ans[i]=0;
        }

        while(q.size())
        {
            int pos = q.front().first;
            int p   = q.front().second;
            q.pop();
            int put = p;
            if(vst[pos]) continue;
            vst[pos] = 1;
            bool st=1;
            for(auto it : v[pos])
            {
                if(it==p) continue;
                if(st)put = it,st=0;
                q.push({it,pos});
            }

            ans[pos] = put;
        }

        for(int i=1;i<n;++i) cout << ans[i] << ' '; cout << endl;
    }
}
