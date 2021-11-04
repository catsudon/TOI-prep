#include<bits/stdc++.h>
#define f first
#define s second
const int MN = 1e5+1;
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
ll sum;
ll qs[MN],a[MN],t[MN];

int ms(int l,int r)
{
    if(l>=r) return 0;
    int mid = (l+r)/2;
    ms(l,mid);
    ms(mid+1,r);

    /// QS
    qs[l] = a[l];
    for(int i=l+1;i<=r;++i) qs[i] = qs[i-1]+a[i];

    int i=l,j=mid+1;
    int pos=l;
    while(i<=mid and j<=r)
    {
        if(a[i] < a[j]) /// this problem want greater<a> and less<b>
        {
            t[pos++] = a[i++];
        }
        else
        {
            sum+=qs[mid]-qs[i]+a[i]+(a[j]*(mid-i+1));
            t[pos++] = a[j++];
        }
    }
    while(i<=mid) t[pos++] = a[i++];
    while(j<=r)   t[pos++] = a[j++];

    for(int i=l;i<=r;++i) a[i] = t[i];

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pll> v(n);
    for(int i=0;i<n;++i)
    {
        int aa,bb; cin >> aa >> bb;
        v[i] = {bb,aa};
    }
    sort(v.begin(),v.end()); // less b
    for(int i=0;i<n;++i) a[i] = v[i].s;
    ms(0,n-1);
    cout << sum;
}
