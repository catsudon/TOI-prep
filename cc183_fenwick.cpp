#include<bits/stdc++.h>
using namespace std;
int a[200009];
int obj[200009];
void update(int i,int val)
{
    for(;i<=200000;i+=i&-i) a[i]+=val;
}

int query(int i)
{
    int sum=0;
    for(;i>0;i-=i&-i) sum+=a[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> obj[i];
    for(int i=1;i<=n;++i) update(i,1);
    for(int oo=0;oo<n;++oo)
    {
        int q; cin >> q;
        int qq = query(q);
        cout << obj[qq] << endl;
        update(q,1);
     //   for(int i=1;i<=n;++i) cout << query(i) << " " ;
     //   cout << endl;
    }
}
