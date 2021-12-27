#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
string board[40];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main()
{
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) cin >> board[i];

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(board[i][j] == '#')
            {
                for(int k=0;k<4;++k)
                {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x < 0 or y < 0 or x >= n or y >= m ) continue;
                    if(board[x][y]=='.') board[x][y] = 'W';
                }
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(board[i][j] == '.')
    {
        int sz = 0;
        queue<pii> q;
        q.emplace(i,j);

        while(!q.empty())
        {
            int F = q.front().f;
            int S = q.front().s;
            q.pop();
            if(board[F][S]!='.') continue;

           // cerr << sz << "  : " << F << S << endl;

            board[F][S] = '@';
            sz++;

            for(int k=0;k<4;++k)
            {
                int x = F+dx[k];
                int y = S+dy[k];
                if(x < 0 or y < 0 or x >= n or y >= m ) continue;
                if(board[x][y] == '.') q.emplace(x,y);
            }


        }

        mx = max(mx,sz);
    }
    cout << mx;


    cerr << endl;
    for(int i=0;i<n;++i) cerr << board[i] << endl;
}
