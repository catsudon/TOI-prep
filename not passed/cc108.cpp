#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int in[150000];
int out[150000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i=1;i<n;++i)
    {
        int a,b,c; cin >> a >> b >>c ;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    //                k    k    k    k
    // by default   1 -> 2 -> 3 -> 4 -> 5
    ll sum = n*k - k;
    for(int i=2;i<=n;++i) in[i] = i-1 , out[i-1]=i;

    for(int i=1;i<=n;++i)
    {
        for(auto it : v[i])
        {
            if(it.s >= k) continue;

        }
    }








}
