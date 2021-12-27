#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    int n,v;
    cin >> n >> v;
    int table[n+1][v+1];
    pair<int,int>items[n+1];
    for(int i=1;i<=n;++i)
    {
        int val,weight; cin >> val >> weight;
        items[i] = {val,weight};
    }
    int val,weight;
    for(int i=0;i<=n;++i)
    {
        if(i!=0)
        {
            val = items[i].f;
            weight = items[i].s;
        }
        for(int j=0;j<=v;++j)
        {
            if(i==0 || j==0) table[i][j]=0;
            else if(j<weight) table[i][j] = max(table[i][j-1],table[i-1][j]);
            else if(j>=weight )
            {
          //      cout << "i = " << i  << " j = " << j  << " "<< val << " " << table[i-1][j-weight] << " " << table[i-1][j] << "\n";
                if(val+table[i-1][j-weight]>table[i-1][j]) table[i][j] = val+table[i-1][j-weight];
                else table[i][j] = max(table[i-1][j],table[i][j-1]);
            }
        }
    }
   /* for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=val;++j) cout << table[i][j] << " ";
        cout << "\n";
    } */
    cout << table[n][v];
}
