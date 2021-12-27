#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
vector<pii> v[200009];
bool vst[200009];

int main()
{
    int n,e; scanf("%d %d",&n,&e);
    for(int i=0;i<e;++i)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }

    priority_queue<pii> p;
    p.push({1,1});

    long long sum=0;
    while(!p.empty())
    {
        int F = p.top().f;
        int S = p.top().s;
        p.pop();
        if(vst[S]) continue;
        vst[S] = true;

        for(auto it : v[S])
        {
            if(!vst[it.s]) p.push(it);
        }

        sum = sum + F - 1;
    }

    cout << sum;
}
