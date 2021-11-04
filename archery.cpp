#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>; /// height :: dot

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<pll> qs(n+1);
    for(int i=1;i<=n;++i) cin >> qs[i].s; // height
    for(int i=1;i<=n;++i) cin >> qs[i].f; // dot

    sort(qs.begin()+1,qs.end());

    ll mnHei = LONG_MAX;
    for(int i=1;i<=n;++i)
    {
        mnHei = min(mnHei,qs[i].s);
        qs[i].f += qs[i-1].f;
        qs[i].s += qs[i-1].s;
    }
    ll bestAns = LONG_MAX;
    ll riru = 0;
  //  for(int i=1;i<=n;++i) cerr << qs[i].s << ":" << qs[i].f << " "; cerr << endl;
    for(int i=1;i<=n;++i)
    {
        ll bonk = qs[i].f-qs[i-1].f;
        if(bonk > mnHei) break;
        ll lChg = qs[i-1].f + (qs[i-1].s-(bonk*(i-1)));
        ll rChg = qs[n].f - qs[i].f - (bonk*(n-i));
        ll sum = lChg+rChg;
    //    cerr << bonk << " : " << lChg << " " << rChg << " " << sum << endl;
     //   bestAns = min(bestAns,sum);
        if(sum < bestAns)
        {
            bestAns = sum;
            riru = bonk;
        }
    }
    cout << riru << " " << bestAns;


}
