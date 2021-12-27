#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll qs[2009][2009];
int mx = -INT_MAX;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,n,k,a; cin >> m >> n >> k;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin >> a,qs[i][j] = qs[i][j-1]+a;

    for(int i=1;i<=m-k+1;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(j<=n-k+1)
            {
            ll s=0;
            for(int l=1;l<=k;++l)
            {
                s+=qs[i+l-1][j+l-1]-qs[i+l-1][j-1];
            }
            if(s>mx) mx=s;
            }
            if(j>=k)
            {
            ll s=0;
            for(int l=1;l<=k;++l)
            {
                s+=qs[i+l-1][j]-qs[i+l-1][j-l];
            }
            if(s>mx) mx=s;
            }
        }

    }
    cout<< mx;




}

