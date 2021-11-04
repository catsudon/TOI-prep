#include<bits/stdc++.h>
using namespace std;
double b[5][5];
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,-1,1,-1,0,1};
int main()
{
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> b[i][j];
    double mn=INT_MAX;
    int perm[n*m];
    for(int i=0;i<n*m;++i) perm[i] = i;

    do
    {
        double sum = 0.0;
        double t[n+2][m+2];
     //   for(int i=0;i<n*m;++i) cout << perm[i] << " ";
       // cout << endl;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) t[i][j] = b[i][j];
        for(int i=0;i<n*m;++i)
        {
            int x = perm[i]/m;
            int y = perm[i]%m;
            sum+=t[x][y];
            for(int i=0;i<8;++i)
            {
                int ax = x+dx[i];
                int ay = y+dy[i];
                if(x<0 or x>=n or y<0 or y>=m) continue;
                t[ax][ay]+= 0.1*t[x][y];
            }

        }
        mn = min(mn,sum);
    }while(next_permutation(perm,perm+n*m));

    printf("%.2f",mn);
}
