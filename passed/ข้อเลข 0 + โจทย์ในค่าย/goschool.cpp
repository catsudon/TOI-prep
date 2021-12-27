#include<bits/stdc++.h>
using namespace std;
int n,m;  //Nrow Mcol
int table[59][59];
int cnt=0;

int start(int x,int y,vector<pair<int,int> > v)
{
    v.push_back({x,y});
    if(x==1 && y==m)
    {
     /*   for(auto it : v) cout << it.first << "," << it.second << " ";
        cout << endl; */
        cnt++;
    }
    else{
        if(table[x-1][y]==0) start(x-1,y,v);
        if(table[x][y+1]==0) start(x,y+1,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    int O; cin >> O;
    int kuy=1;
    for(int i=0;i<O;++i)
    {
        int x,y; cin >> y >> x;
        table[m-x][y] = kuy; kuy++;
    }

    for(int i=0;i<52;++i)
    {
        table[i][m+1] = 1;
        table[0][i]   = 1;
    }
    vector<pair<int,int> > v;
    start(n,1,v);
    cout << cnt;

 /*   for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) if(table[i][j]) cout << table[i][j] << " "; else cout << "O" << " ";
        cout << endl;
    }
*/
}
