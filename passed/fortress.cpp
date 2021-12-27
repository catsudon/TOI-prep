#include<bits/stdc++.h>
using namespace std;
/// idea
/// x+y+z = 12
/// 2(2x+y+z) = 30
/// y+z = 12-x
/// 2x+12-x = 15
/// x=3
/// y+z = 9
/// ans = 10 IDK why

int main()
{
    int q=20;
    while(q--)
    {
        int a,b; cin >> a >> b; // a is always an even number
        int x = (a/2)-b;
        int yz = b-x+1;
        cerr << x << " " << yz << " ";
        if(x<0) cout << 0 << endl;
        else cout << max(0,yz) << endl;
    }
}
