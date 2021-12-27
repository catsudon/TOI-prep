#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    int n,m;
    int mxminion=0;
    cin >> n >> m;
    int arr[n+1];
    pair<int,int> maximum[n+1];
    maximum[0]={0,0};
    for(int i=1;i<=n;++i)
    {
        cin >> arr[i];
        maximum[i] = {0,0};
    }
    int mx = -1;
    for(int i=1;i<=n;++i)
    {
        if(arr[i]+maximum[i-1].f>=0) {
                maximum[i].f+=maximum[i-1].f+arr[i];
                maximum[i].s = maximum[i-1].s+1;
        }
        if(maximum[i].s > m)
        {
            maximum[i].f -= maximum[i-m].f;
            maximum[i].s--;
        }
        if(maximum[i].f>mx) {mx = maximum[i].f; mxminion = maximum[i].s;}
    }
    if(mxminion==0)
    {
        cout << 0;
        return 0;
    }
    cout << mx << "\n" << mxminion;


}
