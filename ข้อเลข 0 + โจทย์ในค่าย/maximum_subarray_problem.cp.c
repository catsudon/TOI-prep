#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    qs[0] = 0;
    int maximum[n+1];
    maximum[0]=0;
    for(int i=1;i<=n;++i)
    {
        cin >> arr[i];
        maximum[i]=0;
    }
    int mx = -1;
    for(int i=1;i<=n;++i)
    {
        if(arr[i]+arr[i-1]>=0) arr[i]+=arr[i-1];
        if(arr[i]>mx) mx = arr[i];
    }

    cout << mx;


}
