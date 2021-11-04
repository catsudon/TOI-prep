#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[262200];
int n,q;

void appudeito(int i,int val)
{
    ll dif = val-a[i];
    a[i] = val;
    i+=i&-i;
    for(;i<=n;i+=i&-i) a[i]+=dif;
}

long long query(int i)
{
    long long sum=0;
    for(;i>0;i-=i&-i)
    {
        sum+=a[i];
    }
    return sum;
}

int main()
{
    cin >> n >> q;
    while(q--)
    {
        char cmd;
        int a,b; cin >> cmd >> a >> b;
        if(cmd=='U') appudeito(a,b);

        if(cmd=='P')
        {
            a--;
            ll sum = query(b) - query(a);
            cout << sum << endl;
        }
    }
}
