#include <bits/stdc++.h>
#define val first
#define idx second
#define N 6000003
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
long long qs[N];
long long mx=0,wide;
deque<pll> q;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> qs[i];
        qs[i] += qs[i-1];
    }

    q.push_back({qs[1],1});
    for(int i=2;i<=n;++i)
    {
        while(!q.empty() and i- q.front().idx > k) q.pop_front();
        while(!q.empty() and q.back().val > qs[i]) q.pop_back();
        q.push_back({qs[i],i});
        if(qs[i] - q.front().val > mx)
        {
            mx = qs[i] - q.front().val;
            wide = i-q.front().idx;
        }
        else if(qs[i] - q.front().val == mx and i-q.front().idx < wide)
                wide = i-q.front().idx;


    }

    cout << mx << endl << wide;
}
