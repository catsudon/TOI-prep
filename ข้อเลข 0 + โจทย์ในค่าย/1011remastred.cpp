#include<bits/stdc++.h>
using namespace std;
int point = 0;
char board[1009][1009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin >> board[i][j];

    int c;
    cin >> c;
    for(int k=0;k<c;++k)
    {
        int a,b;
        char cmd;
        cin >> a >> b >> cmd;
        if(board[a][b]!='-' && board[a][b]!='#')
        {
            if(cmd=='L')
            {
                if(b<=0 || board[a][b-1]=='#') point-=5;
                else if(board[a][b-1]=='-')
                {
                    board[a][b-1] = board[a][b];
                    board[a][b]   = '-';
                }
                else point-=5;
            }
            if(cmd=='R')
            {
                if(b>=m-1 || board[a][b+1]=='#') point-=5;
                else if(board[a][b+1]=='-')
                {
                    board[a][b+1] = board[a][b];
                    board[a][b]   = '-';
                }
                else point-=5;
            }
            //gravity
            int x=1;
            while(x)
            {
                x=0;
                for(int i=0;i<n-1;++i)
                    for(int j=0;j<m;++j)
                    if(board[i][j] != '#' && board[i][j] != '-' && board[i+1][j]=='-')
                    {
                        board[i+1][j] = board[i][j];
                        board[i][j]   = '-';
                    }
                for(int i=0;i<n;++i)
                    for(int j=0;j<m;++j)
                    if(board[i][j] != '#' && board[i][j] != '-')
                    {
                        if(board[i+1][j]==board[i][j])
                        {
                            x++;
                            board[i+1][j] = '-';
                            point+=5;
                        }
                        if(board[i-1][j]==board[i][j])
                        {
                            x++;
                            board[i-1][j] = '-';
                            point+=5;
                        }
                        if(board[i][j+1]==board[i][j])
                        {
                            x++;
                            board[i][j+1] = '-';
                            point+=5;
                        }
                        if(board[i][j-1]==board[i][j])
                        {
                            x++;
                            board[i][j-1] = '-';
                            point+=5;
                        }
                        if(x>0)
                        {  // cout << board[i][j] << " to ";
                            board[i][j] = '-';
                            //cout << board[i][j] << endl;
                            point+=5;
                        }

                        for(int y=0;y<n;++y)
                        {
                            for(int z=0;z<m;++z) cout << board[y][z] <<  " ";
                            cout << "\n";
                        }
                        cout << "\n\n";
                    }
            }
        }
        else point-=5;
    }
    cout << point << "\n";
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
