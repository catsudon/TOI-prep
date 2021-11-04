#include<bits/stdc++.h>
using namespace std;
bool dp[1009][1009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a >> b; a = " " + a; b = " " + b;
    int q; cin >> q;
    while(q--)
    {
        memset(dp,0,sizeof(dp));
        string t;
        cin >> t;
        t = " " + t;
        queue<pair<int,int> > q;
        if(a[1] == t[1]) q.emplace(1,0);
        if(b[1] == t[1]) q.emplace(0,1);
        while(!q.empty())
        {
            int F = q.front().first;
            int S = q.front().second;
            q.pop();
            if(dp[F][S] or F > a.length() or S > b.length()) continue;
           // cerr << F << " " << S << endl;
            dp[F][S] = true;
            if(a[F+1] == t[F+S+1]) if(!dp[F+1][S]) q.emplace(F+1,S);
            if(b[S+1] == t[F+S+1]) if(!dp[F][S+1]) q.emplace(F,S+1);
        }

        dp[a.length()-1][b.length()-1] ? cout << "Yes" : cout << "No";
        cout << endl;
    }
}
