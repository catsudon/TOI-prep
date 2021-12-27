#include<bits/stdc++.h>
using namespace std;

int ar[1009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;++i) cin >> ar[i];
    while(m--)
    {
        int a,b; cin >> a >> b;
        int op = a;
        int ed = a+b-1; ed%=n; if(ed==0) ed=n;
        int cnt = b/2;
        while(cnt--)
        {
            swap(ar[op],ar[ed]);
            op++;
            ed--;
            if(op > n ) op = 1;
            if(ed == 0) ed = n;
        }
    }

    for(int i=1;i<=n;++i) cout << ar[i] << ' ';
}
