#include<bits/stdc++.h>
using namespace std;
int facof[999];

int fac(int n)
{
    if(n==1) return 1;
    if(facof[n-1]!=0 && n-1>1) return facof[n] = n*facof[n-1];
    return facof[n] = n*fac(n-1);
}

int main()
{
    int n,k;
    cin >> n >> k;

    int ans = fac(n)/(fac(n-k)*(fac(k)));
    cout << ans;
}
