#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int MXN = 15000;
using pii = pair<int,int>;

int main()
{
    int n,sum=0;
    cin >> n;
    vector<pii> x(n),y(n);
    pii coor[n];
    for(int i=0;i<n;++i)
    {
        cin >> x[i].x >> y[i].x;
        x[i].y = i;
        y[i].y = i;
        coor[i] = {x[i].x,y[i].x};
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    n--;
    vector<int> v(n+1);
    for(int i=0;i<=n;++i)
    {
        int xlow=0;
        if(x[xlow].y == i) xlow++;
        int xhigh=n;
        if(x[xhigh].y == i) xhigh--;
        int ylow=0;
        if(y[xlow].y == i) ylow++;
        int yhigh=n;
        if(y[xhigh].y == i) yhigh--;
        v[i]=max(
                  max(abs(coor[i].x-x[xlow].x),abs(coor[i].x-x[xhigh].x)),
                  max(abs(coor[i].y-y[ylow].x),abs(coor[i].y-y[yhigh].x))
                  );
    }
    int mn = 0;
    for(auto it : v)
    {
        mn = max(mn,it);
        sum+=it;
       // cerr << it << " ";
    }
  //  cerr << endl;
    cout << sum-mn;


}
