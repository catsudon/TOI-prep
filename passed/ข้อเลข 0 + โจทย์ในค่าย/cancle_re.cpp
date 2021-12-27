#include<bits/stdc++.h>
using namespace std;
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int m,n,c=0;
string table[2000];
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=0;i<m;++i) cin >> table[i];
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(table[i][j]=='1')
            {
                int x=1;
                if(j==0 && i==0 && table[i][j]=='1') c++;
                if(j==0 && i==0) continue;
                if(j!=0) if(table[i][j-1]=='1') x=0;
                if(i!=0 && j!=0) if(table[i-1][j-1]=='1') x=0;
                if(i!=0) if(table[i-1][j]=='1') x=0;
                if(i!=0 && j!=n) if(table[i-1][j+1]=='1') x=0;
                if(x) {c++; cout << i << " " << j << endl;}
            }
        }
    }
    cout << c;
}
