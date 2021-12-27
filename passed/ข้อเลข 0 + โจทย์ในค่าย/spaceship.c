#include<bits/stdc++.h>
using namespace std;

struct shop{
int x,y,z;
int moni,key,cpu;
};

vector<struct shop> v;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;

    cin >> n;

    int monitor=n,keyboard=n,cpu=n;
    int sx,sy,sz;

    cin >> sx >> sy >> sz;

    int shop_count; cin >> shop_count;

    for(int i=0;i<shop_count;++i)
    {
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        v.emplace_back(a,b,c,d,e,f);
    }


}
