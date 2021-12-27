#include<bits/stdc++.h>
using namespace std;
char board[101][101];
int n;
bool rowb[9];
bool colb[9];

bool checkdia(int i,int j)
{
    for(int k=1;i+k<=n && j+k<=n;++k)
    {
        if(board[i+k][j+k]=='X') return false;
    }
    for(int k=1;i-k>0 && j-k>0;++k)
    {
        if(board[i-k][j-k]=='X') return false;
    }
    for(int k=1;i+k<=n && j-k>0;++k)
    {
        if(board[i+k][j-k]=='X') return false;
    }
    for(int k=1;i-k>0 && j+k<=n;++k)
    {
        if(board[i-k][j+k]=='X') return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) board[i][j]='O';
    for(int i=1;i<=8;++i)
    {
        rowb[i]=true;
        colb[i]=true;
    }
    stack<pair<int,int> > st;
    for(int i=1;i<=n;++i)
    {
        int x=0;
        if(rowb[i])
        for(int j=1;j<=n;++j)
        {
            if(board[i][j]=='O')
            {
                if(colb[j])
                {
                    bool dia = checkdia(i,j);
                    if(dia)
                    {
                        board[i][j] = 'X';
                      //  cout << "pushed : " << i << " , " << j << "\n";
                        st.push({i,j});
                        rowb[i]=false;
                        colb[j]=false;
                        x++;
                    }
                }
            }
            if(x) break;
        }
        if(x==0)
        {
            i = st.top().first;
            int j = st.top().second;
            st.pop();
            board[i][j] = '1';
            rowb[i]=true;
            colb[j]=true;
            for(int k=i+1;k<=n;++k){
                for(int l=1;l<=n;++l) board[k][l]='O';
                rowb[k]=true;
            }
            i--;
     /*                   for(int yy=1;yy<=n;++yy)
    {
        for(int jj=1;jj<=n;++jj) //if(board[yy][jj]=='1') cout << 'O' ; else
            cout << board[yy][jj];
        cout << "\n";
    }
    cout << "\n"; */
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j) if(board[i][j]=='1') cout << 'O' ; else
            cout << board[i][j];
        cout << "\n";
    }
}
