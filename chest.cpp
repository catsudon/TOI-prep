#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll cnt[10];
int main()
{
    for(int i=2;i<=7;++i) cnt[i] = 1;
    int n,m; cin >> m >> n;
    vector<pii> v;
    for(int i=0;i<m;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({b,a});
        v.push_back({c+1,-a});
    }
    sort(v.begin(),v.end());
    ll mx=0,tomoriru=0;
    int past = -1;
    for(auto it : v)
    {
        if(it.s > 0)
        {
            if(it.s==2) cnt[2]++;
            if(it.s==3) cnt[3]++;
            if(it.s==4) cnt[2]+=2;
            if(it.s==5) cnt[5]++;
            if(it.s==6) cnt[2]++,cnt[3]++;
            if(it.s==7) cnt[7]++;
            if(it.s==8) cnt[2]+=3;
            if(it.s==9) cnt[3]+=2;
            if(it.s==10) cnt[2]++,cnt[5]++;
            past = it.f;
        }
        else
        {

            ll chg = (ll)cnt[2]*(ll)cnt[3]*(ll)cnt[5]*(ll)cnt[7];

            if(chg > mx) mx = chg,tomoriru=it.f-past;
            else if(chg == mx) tomoriru+=it.f-past;

            if(it.s==-2) cnt[2]--;
            if(it.s==-3) cnt[3]--;
            if(it.s==-4) cnt[2]-=2;
            if(it.s==-5) cnt[5]--;
            if(it.s==-6) cnt[2]--,cnt[3]--;
            if(it.s==-7) cnt[7]--;
            if(it.s==-8) cnt[2]-=3;
            if(it.s==-9) cnt[3]-=2;
            if(it.s==-10) cnt[2]--,cnt[5]--;

        }
    }

    cout << mx << " " << tomoriru;



}
