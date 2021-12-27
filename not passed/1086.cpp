#include<bits/stdc++.h>
using namespace std;
int qs[100010];
//bitset owaru(100010,0);

int main()
{
    int n,k,a,sum=1;
    cin >> n >> k >> a;

    for(int i=0;i<n;++i)
    {
        int peji; cin >> peji;
        sum+=peji;
        for(int i=peji;i<sum;++i) qs[i]++;
    //    owaru[sum] = 1;
    }

    for(int i=k;i<=sum;++i)
    {
        qs[i] += qs[i-1];
    }
    int memo,mx=0;

    for(int i=1;i<=sum;++i)
    {
        int hi = min(sum,i+k*a);
        int temp = qs[hi-1] - qs[i];
        if(temp > mx) mx=temp,memo=i;

    }
    for(int i=1;i<=sum;++i) cout << i << " ";
    cout << endl;
    for(int i=1;i<=sum;++i) cout << qs[i] << " ";
    cout << endl;

    cout << memo << " " << mx;

}
