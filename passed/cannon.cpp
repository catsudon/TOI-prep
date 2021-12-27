#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e7+1;
int n,m,k,l;
int canon[MXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k >> l;

    for(int i=0;i<n;++i)
    {
        int a; cin >> a; a++;
        canon[a] = 1;
    }

    for(int i=1;i<MXN;++i)
    {
        canon[i] = canon[i-1]+canon[i];
    }

    int Lo,Up,nL,nU,num,ans;
    for(int round=0;round<k;++round)
    {
        Lo=-1,Up=-1,ans=0;
        for(int i=0;i<m;++i)
        {
            cin >> num; num++;
            nL = max(1,num-l),nU = min(MXN-1,num+l);
            if(Lo==-1) Lo = nL,Up = nU;
            else if(nL<=Up) Up = nU;
            else
            {
                ans+=canon[Up]-canon[Lo-1];
                Up = nU;
                Lo = nL;
            }
        }
        ans+=canon[Up] - canon[Lo-1];
        cout << ans << "\n";
    }

}
