#include<bits/stdc++.h>
using namespace std;

string ga;
bool not_salt[100009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    int UR = 0;
    int mx=0;
    for(int i=1;i<=k;++i)
    {
        cin >> ga;
        if(ga[0]=='U')
            not_salt[i]=1,UR++;
    }
    mx=UR;

    for(int i=k+1;i<=n;++i)
    {
        cin >> ga;
        if(ga[0]=='U')
            not_salt[i]=1,UR++;
        if(not_salt[i-k]) UR--;
        mx=max(mx,UR);
    }

    cout << mx;

}
