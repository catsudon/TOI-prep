#include<bits/stdc++.h>
using namespace std;
int mx = 0;
int board[4][4] =
    {
        {12,43,78,90},
        {32,78,99,89},
        {12,34,78,12},
        {78,89,99,1}
    };
int start(int x,int y,int p)
{
    p+=board[x][y];
    if(x==3)
    {
        if(p>mx) mx=p;
        return 0;
    }
    if(y-1>=0) start(x+1,y-1,p);
    start(x+1,y,p);
    if(y+1<4) start(x+1,y+1,p);
}

int main()
{
    for(int i=0;i<4;++i)
    {
        start(0,i,0);
    }
    cout << mx;
}
