#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; cin >> n >> m;
    int a[n+1];
    for(int i=1;i<=n;++i) cin >> a[i];
    while(m--)
    {
        char cmd; cin >> cmd;
        if(cmd=='q')
        {
            int to; cin >> to; cout << a[to];
        }
        if(cmd=='b')
        {
            int to,mo; cin >> to >> mo;
            a[to] = mo;
        }
    }
}
