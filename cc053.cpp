#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,int>;
int n,a,b,k,mx;
ppp mon[40];
bool vst[40];
int pts=0;
int ku=0,y=0;

int sol(int round,int tomo,int riru)
{
    if(round > n or abs(ku-y) > k) return 0;
    if(tomo <= 0 or riru <= 0) return 0;
    mx = max(mx,pts);

    cerr << round << " : " << tomo << " " << riru << " " << pts << endl;

    if(round == n)
    {
        return 0;
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            if(vst[i]) continue;
            vst[i] = 1; pts+=mon[i].s;
            ku++; sol(i,tomo-mon[i].f.f,riru); ku--;
            y++;  sol(i,tomo,riru-mon[i].f.s); y--;
            vst[i] = 0; pts-=mon[i].s;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        cin >> n >> a >> b >> k;
        mx=0;
        for(int i=1;i<=n;++i)
            cin >> mon[i].f.f >> mon[i].f.s >> mon[i].s;
        sol(0,a,b);
        cout << mx << endl;
    }
}
