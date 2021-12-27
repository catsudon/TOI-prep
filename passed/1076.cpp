#include<bits/stdc++.h>
using namespace std;
int a[40][40];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m ; cin >> n >> m;
    int all = 1 << m , mn = n;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> a[i][j];


    for(int sim=0;sim<all;++sim)
    {
        int temp = sim;
        vector<int> shin(40,-1); int p=1;
        while(temp) { shin[p++] = temp%2; temp/=2; if(shin[p-1]==0) shin[p-1]=-1; }
        vector<bool> vst(40,0); int lied = 0;
        for(int i=1;i<=m;++i)
        {
            int must_be = shin[i];
            for(int man=1;man<=n;++man)
            {
                if(a[man][i] == 0) continue;
                if(a[man][i] == must_be) continue;
                if(vst[man]) continue;
                vst[man]=1; lied++;
            }
        }

        mn = min(mn,lied);
    }


    cout << mn;
}
