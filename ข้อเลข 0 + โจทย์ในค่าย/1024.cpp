#include<bits/stdc++.h>
using namespace std;

int main()
{
    int mem2,mem3,xd=INT_MAX;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int v[n+5];
    int qs[n+5];
    qs[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin >> v[i];
        qs[i] = qs[i-1]+v[i];
    }

    for(int i=1;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int f = qs[i];
            int s = qs[j]-qs[i];
            int t = qs[n]-qs[j];
            int mx = max(f,s);
            mx = max(mx,t);
            int mn = min(f,s);
            mn = min(mn,t);
            if(mx-mn<xd)
            {
                xd = mx-mn;
                mem2=i+1;
                mem3=j+1;
            }
        }
    }
    cout << mem2 << " " << mem3;
}
