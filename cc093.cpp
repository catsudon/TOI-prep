#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<double,double> coor[1009]; /// x : y
long long sum=0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1;i<=n;++i) cin >> coor[i].x >> coor[i].y;
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            for(int k=j+1;k<=n;++k)
            {
              //  cerr << i << " " << j << " " << k << " : " << slope << " "  << chg << " ";
                if((coor[i].x - coor[j].x) == 0 and (coor[j].x - coor[k].x) == 0) continue;
                if((coor[i].y - coor[j].y) / (coor[i].x - coor[j].x) == (coor[j].y - coor[k].y) / (coor[j].x - coor[k].x) ) continue;
                sum++;
            }
        }
    }
    cout << sum;
}
