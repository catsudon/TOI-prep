#include<bits/stdc++.h>
using namespace std;
bool error[1001]; // include duplicate lib
vector<int> v[1001];
int dp[1001];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        int m; cin >> m;
        vector<bool> listed(1001,false);
        for(int j=0;j<m;++j)
        {
            int t; cin >> t;
            if(listed[t]) error[t] = true;
            else
            {
                v[i].push_back(t); // directed graph
                listed[t] = true;
            }

        }
    }

    for(int i=1;i<=n;++i)
    {
        bool ok = true;
        if(error[i]) ok = false;
        else
        {
            vector<bool> vst(1001,false);
            queue<int> q;
            q.push(i);

            while(!q.empty())
            {
                int num = q.front();
                if(vst[num])
                {
                    ok = false;
                    break;
                }
                q.pop();
                vst[num] = true;

                for(auto it : v[num]) q.push(it);
            }
        }
        ok? cout << "NO\n" : cout << "YES\n";
    }


}
