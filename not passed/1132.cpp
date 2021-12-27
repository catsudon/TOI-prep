#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        int n,k; cin >> n >> k;
        if(n < 2+k) cout << "B\n";
        else cout << "A\n";
    }
}
