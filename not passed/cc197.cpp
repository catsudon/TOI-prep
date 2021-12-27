#include<bits/stdc++.h>
using namespace std;
int a[1509];
int qs[1509];
int n,k;

int sol(int l,int r)
{
    int day = INT_MAX;

    for(int i=l;i<=r;++i)
    {
        int mainnum = a[i];
        int cnt = 0;
        for(int j=l;j<=r;++j)
        {
            cnt+= abs(mainnum - a[j]);
        }
        day = min(day,cnt);
    }



    return day;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i){ cin >> a[i]; qs[i] = qs[i-1]+a[i]; }
    if(k==1)
    {
        cout << sol(1,n); return 0;
    }
    else if(k==2)
    {
        int mn = INT_MAX;
        for(int i=1;i<n;++i) mn = min(sol(1,i)+sol(i+1,n),mn);
        cout << mn;
    }
}
