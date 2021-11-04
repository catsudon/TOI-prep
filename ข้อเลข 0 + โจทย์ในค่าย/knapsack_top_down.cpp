#include<bits/stdc++.h>
#define vl first
#define w second
using namespace std;
int table[900][900];
int n,v;
pair<int,int> items[900];
int start(int x,int y)
{
    if(y<items[x].w)
    {
        table[x][y] = table[x-1][y];
    }
    else if(y>=items[x].w){
        if(items[x].vl+table[x-1][y-items[x].w]>table[x-1][y]) table[x][y] = items[x].vl+table[x-1][y-items[x].w];
        else table[x][y] = table[x][y-1];
    }

    if(y!=v)start(x,y+1);
    else if(x==n) cout << table[x][y];
}

int main()
{
    cin >> n >> v;

    for(int i=1;i<=n;++i){
        int val,w;
        cin >> val >> w;
        items[i] = {val,w};
    }

    for(int i=1;i<=n;++i)
        start(i,1);
}
