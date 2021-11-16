#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,k; cin >> n >> k;

    priority_queue<pair<int,int> > pq; // sum : idx
    int sum; cin >> sum;
    pq.push({-sum,1});
    for(int i=2;i<=n;++i)
    {
        int a; cin >> a;
        while(pq.size() and i-pq.top().s > k)
        {pq.pop();}
        int o = 0;
        if(pq.size()) o = -pq.top().f;
        pq.push({-(a+o),i});

        if(i==n) cout << (a+o);
    }
}
