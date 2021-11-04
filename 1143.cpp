#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int a[1009][4];
const int riru = 50;
int mn = 696969;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=3;++j)
        cin >> a[i][j];

    for(int i=1;i<=riru;++i)
    {
        for(int j=1;j<=riru;++j)
        {
            for(int k=1;k<=riru;++k)
            {
                vector<pii> v;
                for(int l=1;l<=n;++l)
                {
                    int sum = 0;
                    sum += a[l][1]*i + a[l][2]*j + a[l][3]*k;
                    v.push_back({-sum,l});
                }
                sort(v.begin(),v.end());
                int pts=a[1][1]*i + a[1][2]*j + a[1][3]*k;
                int rnk=1;
                for(auto it : v)
                {
                    int F = -it.f;
                    int S = it.s;
                    if(F > pts) rnk++;
                    else break;
                }
            //    if(rnk < mn)
              //  {
         //           cerr << rnk << " " << i << " " << j << " " << k << " " <<  pts << endl;
                //}
                mn = min(mn,rnk);
            }
        }
    }


    cout << mn;

}
