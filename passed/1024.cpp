#include<bits/stdc++.h>
using namespace std;
int mem2,mem3;
int mn = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;

    int qs[n+1];
    qs[0] = 0;

    for(int i=1;i<=n;++i)
    {
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }

    for(int i=1;i<n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            int f,s,t;
            f = qs[i];
            s = qs[j]-qs[i];
            t = qs[n]-qs[j];
            int tmx = max(f,s); tmx = max(tmx,t);
            int tmn = min(f,s); tmn = min(tmn,t);
            int dif = tmx - tmn;
            if(dif < mn)
            {
                mn = dif;
                mem2 = i;
                mem3 = j;
            }
        }
    }

    cout << mem2+1<< " " << mem3+1;
}
