#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v; bool ok=1; int maxlv = 0;

void perm(int sum , int param)
{
    sum=sum*10+param;
    v.emplace_back(sum);
    for(int i=param+1;i<=9;++i) perm(sum,i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    perm(0,0);
    sort(v.begin(),v.end());
    while(q--)
    {
        ll idx; cin >> idx;
        if(idx >= v.size())cout << -1 << '\n';
        else cout << v[idx] << '\n';
    }
}
