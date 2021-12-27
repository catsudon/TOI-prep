#include<bits/stdc++.h>
using namespace std;
long long legend = 98765431;
long long viruscoef[100009],memo;
long long mmemo[39];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    mmemo[0]=1;mmemo[1]=1;
    int k,m; cin >> k >> m;
    for(int i=1;i<=k;++i)
    {
        string a;
        cin >> a;
       // long long coef=1;
        int ii=1;
        for(int j=m-1;j>=0;--j)
        {
            if(mmemo[ii]==0) mmemo[ii] = mmemo[ii-1]*legend;
            viruscoef[i]+=mmemo[ii]*a[j];
            ii++;
        }
    }
    int q; cin >> q;
    for(int i=0;i<q;++i)
    {
        string a;
        int x=1;
        int len; cin >> len >> a;
        long long strcoef=0,coef=1;
        for(int l=m-1;l>=0;--l)
        {
            strcoef+=a[l]*coef;
            if(l==0) memo = coef;
            coef*=legend;
        }
        set<int> affected;
        for(int l=0;l<=len-m;++l)
        {
            for(int j=1;j<=k;++j)
            {
                if(strcoef==viruscoef[j])
                {
                    affected.insert(j);
                    x=0;
                }
            }
            strcoef-=(memo*a[l]);
            strcoef*=legend;
            strcoef+=a[m+l];
        }
        if(x) cout << "OK\n"; else
        {
            for(auto it : affected) cout << it << " ";
            cout << "\n";
        }

    }
}
