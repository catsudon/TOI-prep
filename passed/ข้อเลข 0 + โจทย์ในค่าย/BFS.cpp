#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    int n;
    cout << "Node : ";cin >> n;
    vector<int> v[n+1];
    int e;
    cout << "Edge : ";cin >> e;
    for(int i=0;i<e;++i)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    vector<int> l;
    queue<pair<int,vector<int>> > q;
    q.push({1,l});

    while(!q.empty())
    {
        int F = q.front().f;
        vector<int> S = q.front().s;
        S.push_back(F);
        q.pop();
        if(v[F].size()==0)
        {
            for(auto it : S) cout << it << " ";
            cout << "\n";
            continue;
        }
        for(auto it : v[F])
        {
            q.push({it,S});
        }
    }
}
