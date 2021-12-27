#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
bool vst[15000];
priority_queue<pii,vector<pii>,greater<pii> > pq; // distance :: no.
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,c=0;
    cin >> n >> k;
    priority_queue<int> nr;
    int x[n],y[n];
    vector<pii> v[n];
    for(int i=0;i<n;++i)
    {
        cin >> x[i] >> y[i];
    }
    pq.push({0,0});
    while(!pq.empty())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(vst[S]) continue;
        vst[S] = true;
        c++;
        nr.push(F);
        if(c==n) break;
        for(int i=0;i<n;++i)
        {
            if(i==S) continue;
            pq.push({abs(x[i]-x[S]) + abs(y[i]-y[S]),i});
        }
    }
    long long sum = 0;
   // for(auto it:nr) cout << it << " " ;
   // cout << endl;
    for(int i=0;i<k-1;++i) nr.pop();
    while(!nr.empty())
    {
        sum+=nr.top();
        nr.pop();
    }
    cout << sum;
}
