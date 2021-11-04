#include<bits/stdc++.h>
using namespace std;
int color[4500];
int main()
{
    int n; cin >> n;
    for(int i=0;i<=4100;++i) color[i] = -1;
    while(n--)
    {
        int a; cin >> a;
        color[a]++;
    }

    for(int i=0;i<2100;++i)
    {
        int a = 2017-i;
        int b = 2017+i;
        if(color[a] == 0 )
        {
            cout << a;
            return 0;
        }
        if(color[b] == 0)
        {
            cout << b;
            return 0;
        }
    }
    cout << -1;

}
