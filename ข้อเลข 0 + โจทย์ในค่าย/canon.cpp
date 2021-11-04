#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e7+1;
int canon[MXN],lower,upper,n,nlower,nupper,ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int N,M,K,L;
    cin >> N >> M >> K >> L;

    for(int i=0;i<N;++i)
    {
        int a;cin >> a;a++;
        canon[a]++;
    }
    for(int i=1;i<MXN;++i)
    {
        canon[i] = canon[i-1] + canon[i];
    }

    for(int i=0;i<K;++i)
    {
        lower=-1,upper=-1,ans=0;
        for(int j=0;j<M;++j)
        {
            cin >> n;
            n++;
            nlower = max(1,n-L);
            nupper = min(MXN-1,n+L);
            if(lower==-1)
            {
                lower = nlower;
                upper = nupper;
            }
            else if(upper>=nlower)
            {
                upper = nupper;
            }
            else{
                ans+=canon[upper] - canon[lower-1];
                upper = nupper;
                lower = nlower;
            }

        }
        ans+=canon[upper] - canon[lower-1];
        cout << ans << "\n";
    }

}
