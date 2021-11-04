#include<bits/stdc++.h>
using namespace std;
long long mem[100009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long q; cin >> q;
    double sum = 1;
    long long cnt = 0;
    for(long long i=1;i<=100000;++i)
    {
        sum*=i;
        while(sum >= 10) sum/=10,cnt++;
        mem[i] = cnt;
    }
    while(q--)
    {
        long long n; cin >> n;
        cout << mem[n] << endl;
    }

}
