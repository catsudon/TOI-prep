#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a;
    cin >> n >> m;

    int qs[n+9];
    qs[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin >> a;
        qs[i] = qs[i-1]+a;
    }
    int mx=0,memo;
    for(int i=1;i<=m;++i)
    {
        for(int j=i;j<=n;++j)
        {
            if(qs[j]-qs[j-i]>mx)
            {
                mx = qs[j]-qs[j-i];
                memo = i;
            }
        }
    }

    mx==0 ? cout << 0 : cout << mx << "\n" << memo;

}
