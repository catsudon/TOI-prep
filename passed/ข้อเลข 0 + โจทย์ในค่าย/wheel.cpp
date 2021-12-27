#include<bits/stdc++.h>
using namespace std;
long long len[9];
long long ans=0;

int pt=0;

int lcm(int a,int b)
{
    return __lcm(a,b);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    char k;
    cin >> n >> k;
    string a[n];
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
        len[i] = a[i].length();
    }
    int x;
    while(true)
    {
        ans++;
        x=1;
        for(int i=0;i<n;++i)
        {
            if(a[i][ans%len[i]]!=k) x=0;
        }
        if(x) break;
    }
    cout << ans;
}
