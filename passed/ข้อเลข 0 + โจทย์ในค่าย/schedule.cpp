#include<bits/stdc++.h>
using namespace std;
vector<int> st(500009,0);
vector<int> ed(500009);
int main()
{
    int n,k,m; cin >> n >> k >> m;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        cin >> a >> b;
        st[a] = b;
        ed[b].push_back(i);
    }
    for(int i=1;i<=50000;++i)
    {
        if(st[i]) for(int j=i;j<=st[i];++j)
    }
}
