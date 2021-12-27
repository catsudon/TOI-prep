#include<bits/stdc++.h>
using namespace std;
int n,m;
int table[301][301];
int up[90009],down[90009],rght[90009],lft[90009];
bool vst[301][301];
int cnt = 0;
int solve(int x, int y, int num)
{
    if(x<0 or y<0 or x>=n or y>=m or vst[x][y]) {return 0; cnt = -999;}
    if(cnt==-999) return 0;
    table[x][y] = num;
    vst[x][y] = true;
    cnt++;
    if(rght[num] != -1) solve(x,y+1,rght[num]);
    if(down[num] != -1) solve(x+1,y,down[num]);
    if(lft[num] != -1) solve(x,y-1,lft[num]);
    if(up[num] != -1) solve(x-1,y,up[num]);
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int nm = n*m-1;
    for(int i=0;i<=nm;++i) up[i] = down[i] = rght[i] = lft[i] = -1;
    for(int i=0;i<nm;++i)
    {
        int a,b; char oper;
        cin >> a >> oper >> b;
        if(oper == 'U')
        {
            up[b] = a;
            down[a] = b;
        }
        else
        {
            lft[b] = a;
            rght[a] = b;
        }
    }
    for(int i=n*m-1;i>=0;--i)
    {
        if(rght[i] == -1 and down[i] == -1)
        {
            cnt = 1;
            solve(n-1,m-1,i);
            if(cnt<m*n)
            {
                for(int j=0;j<n;++j) for(int k=0;k<m;++k) vst[j][k] = false;
            }
            else break;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j) cout << table[i][j] << " ";
        cout << endl;
    }
}
