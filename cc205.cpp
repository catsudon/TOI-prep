#include<bits/stdc++.h>
using namespace std;
double qs[10009];

int main()
{
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        scanf("%lf",&qs[i]); qs[i]+=qs[i-1];
      //  cerr << qs[i] << " ";
    }//cerr << endl;
    int rr=0;
    cout << n-k+1 << endl;
    for(int i=1;i<=n-k+1;++i)
    {
        double ans = (qs[i+k-1]*1.0-qs[i-1]*1.0)/k;
        printf("%.6f ",ans);
        rr++;
        if(rr==3)
        {
            rr=0; printf("\n");
        }
    }
}
