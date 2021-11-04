#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const int MXN = 1e5;
ll arr[MXN],t[MXN],sum=0;
ll qs[MXN];

int ms(int l,int r)
{
    if(l>=r) return 0;
    int mid = (l+r)/2;
    ms(l,mid);
    ms(mid+1,r);

    qs[l] = arr[l]; // if we use qs[l-1] will got an error on  l==0
    for(int i=l+1;i<=r;++i) qs[i] = qs[i-1]+arr[i];

    int i=l,j=mid+1;
    int pos=l;
    while(i<=mid and j<=r)
    {
        if(arr[i] < arr[j]) /// ai < aj but bi also < bj
        {
            t[pos++] = arr[i++];
        }
        else
        {
            sum+=arr[j]+qs[mid]-qs[i]+arr[i]+arr[j]*(mid-i);
            t[pos++] = arr[j++];
        }
    }

    while(i<=mid) t[pos++] = arr[i++];
    while(j<=r  ) t[pos++] = arr[j++];
    for(int i=l;i<=r;++i) arr[i] = t[i];
}


int main()
{
    int n; cin >> n;
    vector<pll> v(n);
    for(int i=0;i<n;++i)
    {
        ll a,b; cin >> a >> b;
        v[i] = {b,a};
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;++i) arr[i] = v[i].second;
    ms(0,n-1);
    cout << sum;

}
