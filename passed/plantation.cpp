#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll w; cin >> w;
    while(w--)
    {
        ll n,r,d; bool ok=true; vector<pii> tomo,riru; // x : y
        cin >> n >> r >> d;
        for(ll i=0;i<n;++i)
        {
            ll a,b; cin >> a >> b;
            tomo.push_back({a,b});
            riru.push_back({b,a});
        }
        ll R = 2*r; /// sqrt( abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2) ) - R
        /// if( < ) == !ok
        int nn=8;
      //  if(nn > 50010) nn = 4;
        sort(tomo.begin(),tomo.end()); sort(riru.begin(),riru.end());
        for(int i=0;i<n-1 and ok;++i)
        {
            for(int j=1;j<nn and i+j < n and ok;++j)
            {
                ll x1 = tomo[i].f;
                ll x2 = tomo[i+j].f;
                ll y1 = tomo[i].s;
                ll y2 = tomo[i+j].s;
                if(abs(x1-x2) >= d+R) break;
                double coef = sqrt(abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2));
         //   cerr << x1 << " " << y1 <<  " " << x2 << " " << y2 << " " << coef << endl;
                if(coef < d+R) ok = false;
            }
        }
        for(int i=0;i<n-1 and ok;++i)
        {
            for(int j=1;j<nn and i+j < n and ok;++j)
            {
                ll x1 = riru[i].s;
                ll x2 = riru[i+j].s;
                ll y1 = riru[i].f;
                ll y2 = riru[i+j].f;
                if(abs(y1-x2) >= d+R) break;
                double coef = sqrt(abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2));
         //   cerr << x1 << " " << y1 <<  " " << x2 << " " << y2 << " " << coef << endl;
                if(coef < d+R) ok = false;
            }
        }

        ok ? cout << "Y\n": cout << "N\n";

    }
}
