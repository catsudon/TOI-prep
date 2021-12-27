#include<bits/stdc++.h>
using namespace std;
int pie[59];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int a=0,b=0;
    for(int i=1;i<=n;++i)
    {
        cin >> pie[i];
    }

    for(int i=1;i<=n-2;++i)
    {
        if(i%2==1) b+=pie[i];
        else a+=pie[i];
    }

    int mx = max(pie[n],pie[n-1]);
    int mn = min(pie[n],pie[n-1]);

    if((n-1)%2==1) b+=mx , a+=mn;
    else a+=mx , b+=mn;

    cout <<  a <<  ' ' << b;

}
