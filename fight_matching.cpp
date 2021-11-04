#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long sum=0;
    int n,m; cin >> n >> m;
    vector<int> a(n),b(m);
    vector<bool> vst(100009,false);
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<m;++i) cin >> b[i];
    swap(a,b);
    swap(n,m);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<n;++i)
    {
        int chg = a[i];
        int idx = lower_bound(b.begin(),b.end(),chg)-b.begin();
        if(idx==m) idx--;
        int l = idx;
        int r = idx;
        while(l>=0) if(vst[l]) {l--;} else break;
        while(r< m) if(vst[r]) {r++;} else break;

        int vaL,vaR;
        vaL = abs(chg-b[l]);
        vaR = abs(chg-b[r]);

        if(vaL < vaR)
        {
            sum+=vaL;
            vst[l] = true;
          //  cerr << chg << " : " << b[l] << endl;
        }
        else
        {
            sum+=vaR;
            vst[r] = true;
          //  cerr << chg << " : " << b[r] << endl;
        }
    }
    cout << sum;
}
