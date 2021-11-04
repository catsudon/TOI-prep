#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int hamming(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2) + abs(y1+y2);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    vector<int> nearest(n);
    pii pos[n];

    for(int i=0;i<n;++i)
    {
        int a,b; cin >> a >> b;
        pos[i] = {a,b};
        nearest[i] = INT_MAX;
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i==j) continue;
            nearest[i] = min(nearest[i],hamming(pos[i].f,pos[i].s,pos[j].f,pos[j].s));
        }
    }
    long long sum = 0;

 //   for(auto it : nearest) cerr << it << " " ;
    cerr << endl;
    sort(nearest.begin(),nearest.end());

    for(int i=0;i<n-k+1;++i) sum+=nearest[i];

    cout << sum;



}
