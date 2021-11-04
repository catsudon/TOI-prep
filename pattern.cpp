#include<bits/stdc++.h>
using namespace std;
bool pattern[50010][71];
int main()
{
    int n; cin >> n;
    int mx = -1;
    for(int i=0;i<n;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        mx = max(mx,a);
        for(int i=0;i<c;++i)
        {
           if(b+i < 71) pattern[a][b+i] = true;
        }
    }

    for(int i=1;i<=mx;++i)
    {
        for(int j=1;j<=70;++j)
        {
            if(pattern[i][j]==false) cout << "o";
            else cout << "x";
        }
        cout << "\n";
    }

}
