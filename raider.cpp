#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using ppp = pair<int,pii>; // step :: x/y
int m,n;
int table[105][105];
int vst[101][101]; // x // y // step
queue<ppp> q;
int dx[2][6] = {{1,1,-1,-1,0,0},{1,1,-1,-1,0,0}};
int dy[2][6] = {{-1,0,-1,0,1,-1},{1,0,1,0,1,-1}};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) cin >> table[i][j];
    int op = (m/2)+1;
    if(table[op-1][1] == 1) q.push({1,{op-1,1}});
    if(table[op][1] == 1) q.push({1,{op,1}});
    if(table[op+1][1] == 1) q.push({1,{op+1,1}});
    while(!q.empty()) /// BFS ไม่ต้องกลัวเรื่อง optimization มันดีสุดอยู่แล้ว
    {
        int step = q.front().f;
        int x = q.front().s.f;
        int y = q.front().s.s;
        q.pop();
        if(x==op and y==n)
        {
            cout << step;
            break;
        }
        int coef = x%2;
        int stepplus = step+1;
        for(int i=0;i<6;++i)
        {
            int nx = x+dx[coef][i];
            int ny = y+dy[coef][i];
            if(table[nx][ny] == 0 or ny>n or nx>m or ny<1 or nx<1 ) continue;
            if(vst[nx][ny] == stepplus or stepplus % table[nx][ny] != 0) continue;

            q.push({stepplus,{nx,ny}});
            vst[nx][ny]=stepplus;
        }
    }
}
