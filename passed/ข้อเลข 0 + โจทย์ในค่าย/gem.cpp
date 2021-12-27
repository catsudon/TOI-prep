#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int r=0;r<5;++r)
    {
        int n; cin >> n;
        int m; cin >> m;
        map<int,int> dame;
        map<int,pii> mp;
        for(int i=1;i<=n;++i)
        {
            int a,b;
            cin >> a >> b;
            mp[i] = {a,b};
        }
        for(int i=0;i<m/2;++i)
        {
            int a,b; cin >> a >> b;
            dame[a] = b;
            dame[b] = a;
        }
        int x=0;
        queue<pair<int,vector<int> > > q;
        vector<int> u;
        q.push({0,u});
        while(!q.empty())
        {
            int F = q.front().f;
            vector<int> us1 = q.front().s;
            vector<int> us2 = q.front().s;
            q.pop();
            F++;
            us1.push_back(mp[F].f);
            us2.push_back(mp[F].s);

            if(F==n)
            {
                cout << "         ";
                for(auto it : us1) cout << it << " ";
                cout << endl << "          ";
                for(auto it : us2) cout << it << " ";
                cout << endl;
                if(find(us1.begin(),us1.end(),dame[mp[F].f]) == us1.end() || find(us2.begin(),us2.end(),dame[mp[F].f]) == us2.end())
                    x=1;
            }
            else
            {
            if(find(us1.begin(),us1.end(),dame[mp[F].f]) == us1.end())
            {
                q.push({F+1,us1});
            }
            if(find(us2.begin(),us2.end(),dame[mp[F].f]) == us2.end())
            {
                q.push({F+1,us2});
            }
            }

        }
        if(x) cout << "Y"; else cout << "N";
    }
}
