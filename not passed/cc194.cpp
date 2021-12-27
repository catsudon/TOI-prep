#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using nakadashi = pair<int,pair<int,int> > ;
int a[100009];
vector<nakadashi> lis; // height :: cnt : sum

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> a[i];

    while(n--)
    {
        int chg = a[n];
        if(lis.empty())
        {
            lis.push_front({chg,{1,chg}});
            continue;
        }


    }

}
