#include<bits/stdc++.h>
using namespace std;
const int sze = 1e6+9;
int lft[sze];
int rght[sze];

int main()
{
    int n; cin >> n ;
    for(int i=1;i<=n;++i)
    {
        cin >> lft[i];
        rght[i] = lft[i];
    }
    for(int i=n;i>=1;--i) lft[i] = max(lft[i+1],lft[i]);
    for(int i=1;i<=n;++i) rght[i] = max(rght[i-1],rght[i]);


    for(int i=1;i<n;++i)
    {
        cout << min(rght[i],lft[i+1]) << " ";
    }

}
