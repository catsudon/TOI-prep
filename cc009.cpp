#include<bits/stdc++.h>
using namespace std;
char a[21][1100];
int main()
{
    memset(a,'0',sizeof a);
    int n; string s; cin >> n >> s;
    int x=n,y=1,c=0; // c==n c=0,dir++
    int dir = 0; // 0 = up 1 = right 2 = down 3 = right

    for(auto alp : s)
    {
        a[x][y] = alp;
        c++;
        if(c==n) c=0,dir++;
        dir%=4;
        if(dir==0) x--;
        else if(dir==2) x++;
        else y++;
    }
    string ans = "";
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=10;++j)
        {if(a[i][j]!='0') ans.push_back(a[i][j]);
        cerr << a[i][j];
        }
        cerr << endl;
    }
    cout << ans;
}
