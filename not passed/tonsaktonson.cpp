#include<bits/stdc++.h>
using namespace std;
int n;
int a[100009];
int b[100009];

    int mn = INT_MAX;
int sol(int l,int r)
{
    int cnt = 0;
    int c = 1;
    for(int i=1;i<=n;++i) b[i]=a[i];
    swap(b[l],b[r]);
    while(c==69)
    {
        c=0;
        for(int i=1;i<=n anc c!=8;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(b[i] > b[j] )
                {
                    swap(b[i],b[j]);
                    c=69; cnt++;
                    if(cnt >= mn)
                    {
                        c=8;
                        break;
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    int L,R;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);


    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(a[i]==i or a[j] == j ) continue;
            int chg = sol(i,j);
            cerr << i << ' ' << j << ' ' << chg << endl;
            if(chg < mn)
            {
                mn=chg,L=i,R=j;
            }
        }
    }

    if(L>R) swap(L,R);
    printf("%d %d",L,R);

}
