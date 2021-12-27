#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,fn=1;
    cin >> n >> k;
    vector<int> facof(n+9,-1);
    for(int i=1;i<=n;++i)
        facof[i] = fn*=i;
    int fk = facof[k];
    int fnk = facof[n-k];
    if(fnk==-1) fnk+=2;
    int ans = fn/(fk*fnk);
    cout << ans;
}

