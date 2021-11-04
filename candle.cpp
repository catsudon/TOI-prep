#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,m,F,S,c=0;
int dx[8] = {0,0,1,1,1,-1,-1,-1};
int dy[8] = {1,-1,0,1,-1,0,1,-1};
bool vst[2009][2009];
char table[2009][2009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j)cin >> table[i][j];
    queue<pii> q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(table[i][j]=='1') q.emplace(i,j),c++;
            while(!q.empty())
            {
                tie(F,S) = q.front();
                table[F][S] = '0';
                q.pop();
                if(F>=n or S>=m or F<0 or S<0 or vst[F][S]) continue;
                vst[F][S] = true;
                for(int i=0;i<8;++i)
                {
                    if(table[F+dx[i]][S+dy[i]]=='1' and !vst[F+dx[i]][S+dy[i]]) q.emplace(F+dx[i],S+dy[i]);
                }
            }
        }
    }
    cout << c;
}
