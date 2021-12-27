#include<bits/stdc++.h>
using namespace std;
bool s[50009][79];
int main()
{
    int n; cin >> n;
    int mx=0;
    for(int i=0;i<n;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        mx = max(a,mx);
        for(int j=0;j<c && b+j<=70;++j)
        {
            s[a][b+j] = true;
        }
    }

    for(int i=1;i<=mx;++i)
    {
        for(int j=1;j<=70;++j) s[i][j]==true? cout << "x" : cout << "o";
        cout << "\n";
    }

}
