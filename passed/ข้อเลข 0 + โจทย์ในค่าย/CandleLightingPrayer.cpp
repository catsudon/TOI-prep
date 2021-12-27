/*
TASK: candle.cpp
LANG: C++
AUTHOR: Sathana Laolugsanalerd
CENTER: SSWIT
*/
#include<bits/stdc++.h>
char board[2009][2009];
int m,n,c=0;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int start(int x,int y)
{
    if(board[x][y]=='0' || y<0 || x<=0 || x>m || y>=n) return 0;
    board[x][y]='0';
    for(int i=0;i<8;++i) start(x+dx[i],y+dy[i]);
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    std::cin >> m >> n;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=m;++j)
        std::cin >> board[i][j];
    for(int i=1;i<=m;++i)
    for(int j=0;j<n;++j)
        if(board[i][j]=='1')
            {
                ++c;
                start(i,j);
            }
    std::cout << c;
}
