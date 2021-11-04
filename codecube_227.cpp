#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e9+7;
int kawaii[100009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;++i) cin >> kawaii[i];
    while(q--)
    {
        int l,r,k; cin >> l >> r >> k;
        vector<ll> kawaii_dp(k+3,0);

        kawaii_dp[0] = 1;
        for(int i=l;i<=r;++i)
        {
            for(int j=k;j>=kawaii[i];--j)
            {
                kawaii_dp[j] += kawaii_dp[j-kawaii[i]];
                kawaii_dp[j] %= N;
            }
        }
        cout << kawaii_dp[k] << "\n";
    }
}
