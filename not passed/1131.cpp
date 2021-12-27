#include<bits/stdc++.h>
using namespace std;
int tr[300];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int len; cin >> len;
    string a; cin >> a;
    tr['P'] = 1;
    tr['R'] = 2;
    tr['S'] = 3;
    int sum = 0;
    for(int i=len-1;i>=0;--i)
    {
        sum*=3;
        sum+=tr[a[i]];
        sum%=2003;
    }
    cout << sum;

}
