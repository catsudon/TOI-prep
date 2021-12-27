#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,w; cin >> n >> m >>w;
    int opx,opy,edx,edy; cin >> opx >> opy >> edx >> edy;
    if(w==0)
    {
        int ans = -1;
        if(opx == edx and opy == edy) ans =0;
        else if((opx == edx or opy == edy) and (opx == 1 or opx == n or opy == 1 or opy == m))  ans=1;
        else if(opx == 1 or opx == n or opy == 1 or opy == m) ans=3;
        else ans=3;
        cout << ans;
    }
}
