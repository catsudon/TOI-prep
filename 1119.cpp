#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
pii a[300009];
int qs[300009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n; cin >> n;
    for(int i=0;i<n;++i) cin >> a[i].f , a[i].s=i, a[i].f = -a[i].f;

    sort(a,a+n);
    for(int i=0;i<n;++i) a[i].f = -a[i].f;
    qs[0] = a[0].f;
    for(int i=1;i<n;++i) qs[i] = a[i].f+qs[i-1];

    int mid = qs[n-1]/2 +1;
    int mid_idx = lower_bound(qs,qs+n,mid)-qs;
    int mid_val = a[mid_idx].f;
    bool swapable = 0;
    if(a[mid_idx+1].f == a[mid_idx].f) swapable=1;

    vector<pii> ans; // idx : ans


    //    1   5   4   2   3
    //    7   2   2   2   1
    //    7   9  11  13  14
    //        |                 want = 8 (mid_val)
    //
    for(int i=0;i<n;++i)
    {
        int chg_val = a[i].f;
        int chg_idx = a[i].s;
        int kotae;


        if(chg_val <  mid_val)
        {
            kotae = mid_idx+1;
            if(qs[mid_idx] - mid_val + chg_val >= mid) kotae--; // 9 - 2 + 1 >= 8 ?
        }
        if(chg_val >= mid_val) kotae = mid_idx;

        ans.emplace_back(chg_idx,kotae);

    }
    sort(ans.begin(),ans.end());
    for(auto it : ans) cout << it.s << '\n';




}
