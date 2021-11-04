#include<bits/stdc++.h>
using namespace std;
bool vst[2009];

int main()
{
    int n,k; cin >> n >> k;
    vector<int> v;
    for(int i=2;i<=n;++i)
    {
        if(vst[i] ) continue;
        for(int j=i;j<=n;j+=i)
        {
            if(vst[j]) continue;
            vst[j] = 1;
            v.push_back(j);
        }
    }
    for(auto it : v) cerr << it << " "; cerr << endl;
    cout << v[k-1];
}
