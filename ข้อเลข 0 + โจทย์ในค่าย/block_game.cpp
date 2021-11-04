#include<bits/stdc++.h>
using namespace std;
char board[100][100];
int main()
{
    int m,n;
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) cin >> board[m][n];

    int q; cin >> q;
    for(int i=0;i<q;++i)
    {
        int x,y,cmd;
        cin >> x >> y >> cmd;
        if(cmd=='L')
        {
            if(board[x][y-1]=='-' && y-1>=0) swap(board[x][y],board[x][y-1]);
        }
        if(cmd=='R')
        {
            if(board[x][y+1]=='-' && y+1<n)  swap(board[x][y],board[x][y-1]);
        }
        for(int k=0;k<m-1;++k)
        {
            for(int l=0;l<n-1;++l) if(board[k][l]!='-' && board[k][l]!='#' && board[k+1][l]!='-') swap(board[k][l],board[k+1][l]);
        }
    }
}
