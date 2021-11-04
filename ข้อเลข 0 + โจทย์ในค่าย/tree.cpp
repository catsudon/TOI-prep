#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
for(int r=0;r<5;++r)
{
    int n; cin >> n;
    map<pair<int,int>,bool> m;
    int x=1;
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin >> a >> b;
        m[{a,b}] = true;
        m[{b,a}] = true;
    }
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin >> a >> b;
        if(m[{a,b}]==NULL) x=0;
    }
    if(x) cout << "Y"; else cout << "N";
}
}
