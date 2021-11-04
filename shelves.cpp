#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n;
    vector<int> book(n);

    for(int i=0;i<n;++i) cin >> book[i];

    cin >> q;
    vector<int> borrowed;

    vector<int> pos;
    for(int i=0;i<q;++i)
    {
        int a; cin >> a; a--;

        int cnt = 0;
        for(int i=0;i<pos.size();++i) if(pos[i] <= a) cnt++;

        pos.emplace_back(a-cnt);
        borrowed.emplace_back(book[a+cnt]);

    }

    for(auto it : borrowed) cout << it << "\n";

}
