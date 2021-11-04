#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    int p[n]; for(int i=0;i<n;++i) cin >> p[i];
    int mx=0,a,b,c;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            for(int k=j+1;k<n;++k)
                if(p[i]+p[j]+p[k] <= m and p[i]+p[j]+p[k] > mx)
                {
                    mx = p[i]+p[j]+p[k];
                    a=i,b=j,c=k;
                }

    vector<int> v;
    v.emplace_back(p[a]);
    v.emplace_back(p[b]);
    v.emplace_back(p[c]);
    sort(v.begin(),v.end());
    for(auto it : v) cout << it << endl;

}
