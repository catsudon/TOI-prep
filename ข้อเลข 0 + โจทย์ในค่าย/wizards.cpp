#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<long long,long long>;
int n;
vector<pll> earth;
vector<pll> water;
vector<pll> wind;
vector<pll> fire;
unordered_map<ll,bool> xfire;
ll demonx,demony;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cin >> demonx >> demony >> n;
    for(int i=0;i<n;++i)
    {
        int x,y; cin >> x >> y;
        earth.push_back({x,y});
    }
    for(int i=0;i<n;++i)
    {
        int x,y; cin >> x >> y;
        water.push_back({x,y});
    }
    for(int i=0;i<n;++i)
    {
        int x,y; cin >> x >> y;
        wind.push_back({x,y});
    }
    for(int i=0;i<n;++i)
    {
        int x,y; cin >> x >> y;
        fire.push_back({x,y});
        ll key = (97*x+31*y)-(98765431*(x-y));
        xfire[key] = true;
    }

    for(auto et : earth)
    {
        ll etx = et.f,ety = et.s;
        for(auto wt : water)
        {
            ll wtx = wt.f,wty = wt.s;
            for(auto wd : wind)
            {
                ll wdx = wd.f,wdy = wd.s;
                int fx = demonx - etx - wtx - wdx;
                int fy = demony - ety - wty - wdy;
                if(xfire[(97*fx+31*fy)-(98765431*(fx-fy))]!=NULL)
                    {
                        cout << etx << " " << ety << "\n" << wtx << " " << wty << "\n" << wdx << " " << wdy << "\n" << fx << " " << fy;
                        return 0;
                    }
            }
        }
    }
}
