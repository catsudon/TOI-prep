#include<bits/stdc++.h>
using namespace std;
int up [90009];int down [90009];int LEFT [90009];int RGHT [90009];
int n,m,cnt;
int table[309][309];
bool vst[300][300];

int start(int x, int y,int num)
{
    if(x==n or y==m or x<0 or y<0 or vst[x][y]) return 0;
    cnt++;
    table[x][y] = num;
    vst[x][y] = true;
    if(RGHT[num]!=-1) start(x,y+1,RGHT[num]);
    if(down[num] !=-1) start(x+1,y,down[num]);

    if(LEFT[num]!=-1) start(x,y-1,LEFT[num]);
    if(up[num]  !=-1) start(x-1,y,up[num]);

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<=n*m;++i)
    {
        up[i]=-1;
        down[i]=-1;
        LEFT[i]=-1;
        RGHT[i]=-1;
    }

    for(int i=1;i<n*m;++i)
    {
        int a,b; char oper;
        cin >> a >> oper >> b;
        if(oper=='U')
        {
            up[b]=a;
            down[a]=b;
        }
        else
        {
            LEFT[b]=a;
            RGHT[a]=b;
        }
    }

    for(int i=n*m-1;i>=0;--i)
    {
        if(RGHT[i]==-1 and down[i]==-1)
        {
            cnt =1;
            start(n-1,m-1,i);
            if(cnt<m*n)
            {
                for(int ii=0;ii<n;++ii)for(int jj=0;jj<m;++jj) vst[ii][jj] = false;
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
