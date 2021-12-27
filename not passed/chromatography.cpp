#include<bits/stdc++.h>
using namespace std;
const MXN = 1e6;

int a[MXN+9];
void appudeito(int i,int val)
{
    while(i<=MXN)
    {
        i+=i&-i;
        a[i]+=val;
    }
}
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=a[i];
        i-=i&-i;
    }
}

int main()
{
    int n,t; cin >> n >> t;
    while(n--)
    {
        int s,h,w,o; cin >> s >> h >> w >> o; /// start : height : length : weight

    }
}
