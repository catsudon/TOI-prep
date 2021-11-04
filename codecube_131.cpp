#include<bits/stdc++.h>
using namespace std;
int c1,c2,c3;
int main()
{
    int a,b; cin >>a >> b;
    vector<int> v1(a),v2(b);
    for(int i=0;i<a;++i) cin >> v1[i];
    for(int i=0;i<b;++i) cin >> v2[i];

    sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
    if(v1.size()>=2) c1 = v1[0]+v1[1];
    if(v2.size()>=2) c2 = v2[0]+v2[1];
    c3 = v1[0]+v2[0]+100;

    if(v1.size()==1 and v2.size()==1) {cout << c3; return 0;}

    int mn = c3;
    if(v1.size()>=2) mn = min(mn,c1);
    if(v2.size()>=2) mn = min(mn,c2);
    cout << mn;
}
