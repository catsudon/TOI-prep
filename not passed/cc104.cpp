#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
int a[1009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    vector<pair<int,int> > lis;

    lis.push_back({a[1],1});

    for(int i=2;i<=n;++i)
    {
        int lower_bound_index = lower_bound(lis.begin(),
                                            lis.end(),
                                            make_pair(a[i],-1)
                                            ) - lis.begin();

        if(lower_bound_index == lis.size() or a[i] > lis[lis.size()-1].f)
        {
            lis.push_back({a[i],lis[lower_bound_index-1].s+1});
            continue;
        }

        int index = lower_bound_index ;
        index--;
        if(index < 0)
        //  2:1 3:2 4:3  a[i] = 1
        {
            lis[0].f = a[i];
            continue;
        }

        //  2:1 3:2 5:3     a[i] = 4
        else
        {
            lis[index+1].f = a[i];
        }

    }


    for(auto it : lis)
    {
        cerr << it.f << ':' << it.s << ' ';
    }


    cout << n-lis.back().s;

}



/*
6
1 5 10 15 14 6
1:1 5:2 6:3 14:4
*/
