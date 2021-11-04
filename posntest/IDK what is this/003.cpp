#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int sze = 1e6+9;

ll qs[sze];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;++i)
    {
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }

    while(q--)
    {
        int op,ed; scanf("%d%d",&op,&ed);
        ll kitai = (qs[ed] - qs[op])/2;
        kitai = kitai+qs[op];           // cerr << lwb_kt << "  : ";
        ll l=op,r=ed;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(qs[mid] >= kitai) r=mid-1;
            else l=mid+1;
        }
        int idx=l;
     //   cerr << kitai << endl;
        ll mn = LONG_MAX;
        for(int i=-1;i<=1;++i)
        {
            ll aidx = idx+i;
            if(aidx < op or aidx > ed) continue;
            mn = min(mn,max(qs[ed]-qs[aidx],qs[aidx]-qs[op]));
        }
  //      cerr << "idx = " << idx << " val = " << qs[idx] << " " << chg1 << endl;
        printf("%lld\n",mn);

    }
}
