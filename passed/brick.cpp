#include<bits/stdc++.h>
using namespace std;
int start[21] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
char board[21][21];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
        {
            cin >> board[i][j];
            if(board[i][j]=='O') if(start[j]==-1) start[j]=i;
        }
    int fallen[m];
    for(int i=0;i<m;++i) cin >> fallen[i];
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<fallen[i] && j<21;++j)
        {
            if(start[i]==-1 && n-1-j >=0) board[n-1-j][i] = '#';
            else
            {
                if(start[i]-j-1>=0)board[start[i]-j-1][i] = '#';
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j) cout << board[i][j];
        cout << "\n";
    }
}
