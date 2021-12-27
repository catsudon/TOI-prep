#include<bits/stdc++.h>
using namespace std;
char wow[309][309];
bool vst[309];
int mx = -1;
int n,m;
bool check(int a,int b,int k)
{
    if(k%2==1)
    for(int i=a , pi=a+k-1 ; i<=a+k/2+1 ; ++i , --pi)
    {
        for(int j=b , pj=b+k-1 ; j<b+k ; ++j , --pj) if(wow[i][j] != wow[pi][pj]) return 0;
    }
    else
    for(int i=a , pi=a+k-1 ; i<=a+k/2 ; ++i , --pi)
    {
        for(int j=b , pj=b+k-1 ; j<b+k ; ++j , --pj) if(wow[i][j] != wow[pi][pj]) return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j) cin >> wow[i][j];
    }
  /*  int p=2;
    int cnt = 1;
    int csm = 2; // surely completed
    while(cnt!=min(n,m))
    {
        if(p>min(n,m)) p--;
        if(vst[p]) p++;
        int k=p;
        for(int i=n-k+1;i>=1;--i)
        {
            for(int j=1;j<=m-k+1;++j)
            {
                // check
                bool epic = check(i,j,k);
                if(epic)
                {
                    mx = max(mx,k);
                }
            }
        }
        //                  mx                 see that if mx == 6 we don't have to compute <=6 anymore
        //         10 9 8 7 6 5 4 3 2
        //      if not , just move up 1 step higher
        vst[p]=1; cnt++;
        if(mx == k)  // matched , no need to compute lower number
        {
            for(int i=p;i>=2;--i) if(!vst[i]) vst[i]=1,cnt++;
            csm = k , p = (csm+min(n,m))/2+1;
        }
        else csm++,p=csm;
    //    cerr << " k = " << k << " cnt = "<< cnt << endl;
    } */
    for(int k=min(n,m);k>=2;--k)
    {
       // for(int i=1;i<=n-k+1;++i)
        for(int i=n-k+1;i>=1;--i)
        {
            for(int j=1;j<=m-k+1;++j)
            {
                // check
                bool epic = check(i,j,k);
                if(epic)
                {
                    cout << k; return 0;
                }
            }
        }
    }
    cout << mx;
}
