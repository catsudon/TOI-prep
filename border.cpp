#include<bits/stdc++.h>
using namespace std;
int ue[109][109],hidari[109][109];

int main()
{
    int n,k; cin >> n >> k;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) cin >> ue[i][j];
        for(int j=0;j<=n;++j) cin >> hidari[i][j];
    }
    for(int j=0;j<n;++j) cin >> ue[n][j];

    vector<int> sum;

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int s = 3*ue[i][j] + 5* hidari[i][j] - 3*ue[i+1][j] - 5*hidari[i][j+1];
            sum.emplace_back(s);
        }
    }
    sort(sum.begin(),sum.end()); int realsum = 0;
    for(int i=0;i<k;++i) realsum+=sum[i];

    cout << realsum;
}
