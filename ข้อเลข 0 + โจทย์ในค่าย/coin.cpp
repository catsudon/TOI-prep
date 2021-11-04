#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    int n,v;
    cin >> n >> v;
    int table[n+1][v+1];
    int coin[n+1];
    for(int i=1;i<=n;++i) cin >> coin[i];
    int val;
    for(int i=0;i<=n;++i)
    {
        if(i!=0)
        {
            val = coin[i];
        }
        for(int j=0;j<=v;++j)
        {
            if(i==0 || j==0) table[i][j]=0;
            else if(j<val) table[i][j] = table[i-1][j];
            else if(j>=val)
            {
                table[i][j] = j/val+table[i-1][j-val];
            }
        }
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=v;++j) cout << table[i][j] << " ";
        cout << "\n";
    }
    cout << table[n][v];
}
