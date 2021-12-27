#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5+9;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; scanf("%d%d",&k,&n);
    ll sum=0;
    for(ll i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(n>k)
    {
        printf("-1"); return 0;
    }
    ll l = 1,r=LONG_MAX-1000009;
    while(l<=r)
    {
        ll mid = (l+r)/2;
        ll cnt = 0;
        for(ll i=1;i<=n;++i)
        {
            if(a[i] <= mid) cnt++;
            else
            {
                cnt+=a[i]/mid;
                if(a[i]%mid!=0) cnt++;
            }

    //        cerr << cnt << ' ';
        }
    //    cerr << "_______________" << mid << "__________________\n";

        if(cnt > k) l=mid+1;
        if(cnt <= k ) r=mid-1;
    }

    printf("%lld",l);
}
