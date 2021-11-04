#include<bits/stdc++.h>
using namespace std;
int sky[3009];
int main()
{
    int n; cin >> n;
    int mx=0;
    for(int i=0;i<=280;++i) sky[i]=0;
    for(int i=0;i<n;++i)
    {
        int a,h,b;
        cin >> a >> h >> b;
        mx = max(mx,b);
        for(int j=a;j<b;j++) sky[j] = max(sky[j],h);
    }
    sky[0] = 0;
    for(int i=1;i<=256;++i)
    {
        if(sky[i]!=sky[0]) cout << i << " " << sky[i] << " ";
        sky[0] = sky[i];
    }
}
