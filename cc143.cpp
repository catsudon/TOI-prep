#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v[30001];
vector<int> e[30001];
int main()
{
    cin >> n >> m;
    for(int i=1;i<n;++i)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int c=0;
    for(int i=1;i<=n;++i)
    {
        if(v[i].size() == 1)
        {
            c++;
            e.emplace_back(i);
        }
    }
    cout << (c+1)/2;
}
