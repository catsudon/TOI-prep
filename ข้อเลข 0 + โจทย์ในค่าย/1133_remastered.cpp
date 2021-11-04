#include<bits/stdc++.h>
using namespace std;
vector<int> transportable[1009]; // 1M
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int s; cin >> s;
        int station[s];
        for(int j=0;j<s;++j)
        {
            cin >> station[j];
        }
        for(int j=0;j<s;++j)
        {
            for(int k=j+1;k<s;++k)
            {
                transportable[station[j]].push_back(station[k]);
                transportable[station[k]].push_back(station[j]);
            }
        }

    }
    for(int i=1;i<=n;++i)
    {
        for(auto it : transportable[i]) cout << it << " ";
        cout << "\n";
    }
}
