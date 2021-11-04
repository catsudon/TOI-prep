#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppp = pair<ll,pii>;
int a[1009][1009];
bool vst[1009][1009];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int q; cin >> q;
    while(q--)
    {
        ll n,m; cin >> n >> m;
        int opx,opy; cin >> opx >> opy;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {cin >> a[i][j]; vst[i][j] = 0;}

        ll rage = a[opx][opy];
        ll sum = 0;
        priority_queue<ppp,vector<ppp>,greater<ppp> > pq;
        pq.push({rage,{opx,opy}});

        while(pq.size())
        {
            ll chg = pq.top().f;
            int x  = pq.top().s.f;
            int y  = pq.top().s.s;
            pq.pop();
            if(vst[x][y]) continue;
            vst[x][y] = 1;
            rage = max(rage,chg);
            sum+=chg;
            if(sum >=m ) break;
            for(int i=0;i<4;++i)
            {
                int ax = x+dx[i];
                int ay = y+dy[i];
                if(ax < 1 or ay < 1 or ax > n or ay > n ) continue;
                if(vst[ax][ay]) continue;
                pq.push({a[ax][ay],{ax,ay}});
            }
        }
        cout << rage << endl;
    }
}
