#include<bits/stdc++.h>
using namespace std;
int k[1009];
int h[1009];




int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> k[i] >> h[i];

    for(int i=1;i<=n;++i)
    {
        if(k[i]==h[i]) continue;
        if(k[i]>h[i])
        {
            for(int j=1;j<=m and k[i]!=h[i];++j)
            {
                if(h[i]+h[i+j] < k[i]) h[i]+=h[i+j] , h[i+j]=0;
                else
                {
                    h[i+j] -= k[i] - h[i];
                    h[i] = k[i];
                    break;
                }
            }
        }
        else
        {
            for(int j=1;j<=m and k[i]!=h[i];++j)
            {
                if(k[i]+k[i+j] < h[i]) k[i]+=k[i+j] , k[i+j]=0;
                else
                {
                    k[i+j] -= h[i] - k[i];
                    k[i] = h[i];
                    break;
                }
            }
        }
    }

    for(int i=1;i<=n;++i)
    {
        if(k[i]!=h[i]) {cout << "NO"; return 0;}
    }
    cout << "YES";
}
