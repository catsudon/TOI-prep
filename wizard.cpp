#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii = pair<int,int>;
pii maou;
int n;
map<pii,bool> have_b,have_d;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> maou.x >> maou.y >> n;
    vector<pii> a(n),b(n),c(n),d(n);

    for(int i=0;i<n;++i) cin >> a[i].x >> a[i].y;
    for(int i=0;i<n;++i)
    {
        cin >> b[i].x >> b[i].y;
        have_b[b[i]] = true;
    }
    for(int i=0;i<n;++i) cin >> c[i].x >> c[i].y;
    for(int i=0;i<n;++i)
    {
        cin >> d[i].x >> d[i].y;
        have_d[d[i]] = true;
    }
    vector<pii> sum_ab;
    vector<pii> sum_cd;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
                sum_ab.emplace_back(a[i].x+b[j].x , a[i].y+b[j].y);

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
                sum_cd.emplace_back(c[i].x+d[j].x , c[i].y+d[j].y);

    sort(sum_ab.begin(),sum_ab.end()); sort(sum_cd.begin(),sum_cd.end());

    for(auto ab : sum_ab)
    {
        int wx = maou.x-ab.x;
        int wy = maou.y-ab.y;
        int p = lower_bound(sum_cd.begin(),sum_cd.end(),make_pair(wx,wy)) - sum_cd.begin();
        if(p>=sum_cd.size()) continue;
        if(sum_cd[p].x > wx or sum_cd[p].y > wy) continue;

        // reverse engineer
        for(auto it : a)
        {
            int wwx = ab.x-it.x;
            int wwy = ab.y-it.y;
            if(have_b[{wwx,wwy}])
            {
                cout << it.x << " " << it.y << "\n" << wwx << " " << wwy << "\n";
                break;
            }
        }
        for(auto it : c)
        {
            int wwx = sum_cd[p].x-it.x;
            int wwy = sum_cd[p].y-it.y;
            if(have_d[{wwx,wwy}])
            {
                cout << it.x << " " << it.y << "\n" << wwx << " " << wwy << "\n";
                break;
            }
        }


        return 0;

    }





}
