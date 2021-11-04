/*
TASK: 0110SS.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Sathana Laolugsanalerd
ID: SSWIT
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    unsigned long long ans[n+1];
    ans[0]=0;ans[1]=2;ans[2]=3;
    for(int i=3;i<=n;++i)
        ans[i] = ans[i-1]+ans[i-2];
    cout << ans[n];
}
