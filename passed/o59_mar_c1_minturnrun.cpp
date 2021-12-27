#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,pii>; // turn:dir :: x:y

int dx[] = {-1,0,1};
int dy[] = {0,1,0};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,op; cin >> n >> m >> op;

    /// define direction
    // up 0 right 1 down 2 left 3

    int  vst[n+1][m+1];
    bool board[n+1][m+1];
    for(int i=0;i<=n;++i) for(int j=0;j<=m;++j)
    vst[i][j] = INT_MAX;

    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        char t ; cin >> t;
        if(t=='#') board[i][j] = 1;
        else board[i][j] = 0;
    }

    priority_queue<ppp,vector<ppp>,greater<ppp> > pq; // turn:dir :: x:y
    pq.push({{0,1},{op,1}});

    while(pq.size())
    {
        int turn = pq.top().f.f;
        int dir  = pq.top().f.s;
        int x    = pq.top().s.f;
        int y    = pq.top().s.s;
        pq.pop();

        if(y==m)
        {
            cout << turn;
            return 0;
        }

        for(int i=0;i<3;++i)
        {
            int ax = x+dx[i];
            int ay = y+dy[i];
            if(ax < 1 or ay < 1 or ax > n or ay > m or board[ax][ay]) continue;
            int coef = 1;
            if(dir == i) coef=0;
            if(vst[ax][ay] <= turn+coef) continue;
            pq.push({{turn+coef , i},{ax,ay}});
            vst[ax][ay]=turn+coef;
        }

    }


 /*   for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            bool ew = 0;
            for(int k=0;k<3;++k) if(vst[i][j][k]) ew=1;
            if(board[i][j] == '#') cout << "# ";
            else if(ew) cout << "o ";
            else cout << ". ";
        }
        cout << endl;
    } */
    cout << -1;



}
