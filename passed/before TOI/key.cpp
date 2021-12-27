#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

bool dp[1009][1009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    string a,b; cin >> a >> b;
    a=" "+a; b=" "+b;

    int qu; cin >> qu;
    while(qu--)
    {
        for(int i=0;i<=a.length();++i) for(int j=0;j<=b.length();++j) dp[i][j]=0;
        string s; cin >> s; s=" "+s;
        queue<pii> q;
        if(s[1] == a[1]) q.push({1,0});
        if(s[1] == b[1]) q.push({0,1});
        while(q.size())
        {
            int F = q.front().f;
            int S = q.front().s;
            q.pop();

            if(dp[F][S]) continue;
            dp[F][S] = 1;
       //     cerr << F << ' ' << S << endl;

            if(F+1<a.length() and a[F+1] == s[F+S+1]) q.push({F+1,S});
            if(S+1<b.length() and b[S+1] == s[F+S+1]) q.push({F,S+1});



        }

        if(dp[a.length()-1][b.length()-1]) cout << "Yes\n";
        else cout << "No\n";

    }

}
