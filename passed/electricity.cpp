#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    int num[n];
    int dp[n];
    for(int i=0;i<n;++i) cin >> num[i];
    priority_queue<pii> pq; // sum and index
    pq.emplace(-num[0],0);
    for(int i=1;i<n;++i)
    {
        while(!pq.empty() and i-pq.top().s>k) pq.pop();
        dp[i] = -pq.top().f + num[i];
        pq.emplace(-dp[i],i);
    }


    cout << dp[n-1];
}
