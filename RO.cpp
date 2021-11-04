#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; string s;
    cin >> n >> k >> s;

    int mx=0;
    int now=1,memo=1;
    for(int i=1;i<n;++i)
    {
        if(s[i] == s[i-1]) memo++;
        else memo = 1;

        if(memo > k ) memo = k,now = k;
        else now++;

        mx = max(mx,now);
    }

    cout << mx;
}
