#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>;
int main()
{
    int n,k; cin >> n >> k;
    long long sum=0;
    vector<ppp> dis;
    vector<bool> vst(n+9,false);
    int pos[n]; cin >> pos[0];
    for(int i=1;i<n;++i)
    {
        cin >> pos[i];
        for(int j=i-1;j>=0;--j)
        dis.push_back({pos[i]-pos[j],{j,i}});
    }
    sort(dis.begin(),dis.end());
    int c=0,idx=0;
    while(c!=k)
    {
        int a = dis[idx].s.f;
        int b = dis[idx].s.s;
        int len = dis[idx].f;
        if(vst[a] or vst[b]) continue;
        vst[a] = true;
        vst[b] = true;
        sum+=len;
        c++; idx++;
    }

    cout << sum;
}
