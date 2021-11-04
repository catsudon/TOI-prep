#include<bits/stdc++.h>
using namespace std;
int board[300][300];
int copycat[300][300];
int m,n,c=0;
int ans[1000];
int ue[4] = {13,14,21,31};
int shita[4] = {11,12,21,31};
int migi[4] = {11,13,22,31};
int hidari[4] = {12,14,22,31};
int start(int x,int y,int no,int maex,int maey)
{
    ans[no]++;
 //   cout << x << " " << y << " " << ans[no] << endl;
    if(board[x][y]==0) return 0;
    if(board[x][y]==11)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x-1>=0)if(board[x-1][y]==ue[i]) start(x-1,y,no,x,y);
            if(y-1>=0)if(board[x][y-1]==hidari[i]) start(x,y-1,no,x,y);
        }

    }
    else if(board[x][y]==12)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x-1>=0)if(board[x-1][y]==ue[i]) start(x-1,y,no,x,y);
            if(y+1<n)if(board[x][y+1]==migi[i]) start(x,y+1,no,x,y);
        }

    }
    else if(board[x][y]==13)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x+1<m)if(board[x+1][y]==shita[i]) start(x+1,y,no,x,y);
            if(y-1>=0)if(board[x][y-1]==hidari[i]) start(x,y-1,no,x,y);
        }

    }
    else if(board[x][y]==14)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x+1<m)if(board[x+1][y]==shita[i]) start(x+1,y,no,x,y);
            if(y+1<n)if(board[x][y+1]==migi[i]) start(x,y+1,no,x,y);
        }

    }
    else if(board[x][y]==21)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(x-1>=0)if(board[x-1][y]==ue[i]) start(x-1,y,no,x,y);
            if(x+1<m)if(board[x+1][y]==shita[i]) start(x+1,y,no,x,y);
        }

    }
    else if(board[x][y]==22)
    {
        board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(y+1<n)if(board[x][y+1]==migi[i]) start(x,y+1,no,x,y);
            if(y-1>=0)if(board[x][y-1]==hidari[i]) start(x,y-1,no,x,y);
        }

    }
    else if(board[x][y]==31)
    {
       // board[x][y]=0;
        for(int i=0;i<4;++i)
        {
            if(y+1<n and board[x][y+1]==migi[i] and (copycat[maex][maey]==12||copycat[maex][maey]==14||copycat[maex][maey]==22||copycat[maex][maey]==31) and maey == y-1 )
            {
                board[x][y] = 21;
                copycat[x][y] = 21;
                start(x,y+1,no,x,y);
            }
            else if(y-1>=0 and board[x][y-1]==hidari[i] and (copycat[maex][maey]==11||copycat[maex][maey]==13||copycat[maex][maey]==22||copycat[maex][maey]==31) and maey == y+1 )
            {
                board[x][y] = 21;
                copycat[x][y] = 21;
                start(x,y-1,no,x,y);
            }
            else if(x-1>=0 and board[x-1][y]==ue[i] and (copycat[maex][maey]==11||copycat[maex][maey]==12||copycat[maex][maey]==21||copycat[maex][maey]==31) and maex == x+1)
            {
                board[x][y] = 22;
                copycat[x][y] = 22;
                start(x-1,y,no,x,y);
            }
            else if(x+1<m and board[x+1][y]==shita[i] and (copycat[maex][maey]==13||copycat[maex][maey]==14||copycat[maex][maey]==21||copycat[maex][maey]==31) and maex == x-1 )
            {
                board[x][y] = 22;
                copycat[x][y] = 22;
                start(x+1,y,no,x,y);
            }
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;++i) for(int j=0;j<n;++j) {cin >> board[i][j];copycat[i][j] = board[i][j];}
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
        if(board[i][j]!=0)
        {   start(i,j,c,0,0); c++;    }
    int copyc = c;
   // for(int i=0;i<copyc;++i) if(ans[i]=1) c--;
    cout << c << "\n";
    for(int i=0;i<copyc;++i) //if(ans[i]!=1)
        cout << ans[i] << " ";
}
